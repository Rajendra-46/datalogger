pipeline {
    agent {
        docker {
            image 'iharsha2022/imageqt'
            reuseNode true
        }
    environment {
        REPOSITORY_NAME = "Analyser-Application"
        ARTIFACT_NAME   = "Datalogger-V-1.1.1"
    }
    options {
        timeout(time: 20, unit: 'MINUTES')
        buildDiscarder(logRotator(numToKeepStr: '30', artifactNumToKeepStr: '10'))
        copyArtifactPermission('*')
        timestamps()
    }
    stages {
        stage('Project Configuration') {
            steps {
                script {
                    def folders = sh(script: 'ls -d */ | grep -v "@" | wc -l', returnStdout: true).trim()
                    def folderName
                    if ( folders.toInteger() == 0) {
                        def zipFiles = sh(script: 'ls *.zip', returnStdout: true).trim()
                        def zipFileCount = zipFiles.tokenize('\n').size()
                        if (zipFileCount == 0) {
                            error "No ZIP file found"
                        } 
                        else if (zipFileCount == 1) {
                            def zipFile = zipFiles.tokenize('\n')[0].trim()
                            sh "unzip \"${zipFile}\""
                        } 
                        else {
                            def codeZipFile = zipFiles.tokenize('\n').find { it.toLowerCase().contains('code') }
                            if (codeZipFile) {
                                sh "unzip \"${codeZipFile}\""
                            } 
                            else {
                                error "Multiple ZIP files found but none with 'code' in the name"
                            }
                        }
                        def proFile = sh(script: 'find . -name "*.pro" -maxdepth 4', returnStdout: true).trim()
                        if (proFile.isEmpty()) {
                            error "No .pro file found within 4 levels of depth"
                        } 
                        else {
                            folderName = proFile.replaceAll(/\/[^\/]+\.pro$/, '')
                            echo "zip folder :${folderName}"
                        }
                    }
                    else if (folders.toInteger() == 1 ) {
                        def proFile = sh(script: 'find . -name "*.pro" -maxdepth 4', returnStdout: true).trim()
                        folderName = proFile.replaceAll(/\/[^\/]+\.pro$/, '')
                        echo "Single folder found: ${folderName}"
                    } 
                    else if (folders.toInteger() == 2) {
                        def proFile = sh(script: 'find . -name "*.pro" -maxdepth 4', returnStdout: true).trim()
                        folderName = proFile.replaceAll(/\/[^\/]+\.pro$/, '')
                        //folderName = sh(script: 'ls -d */ | grep -i "code"  | sed -n "s/\\([a-zA-Z0-9_-]*\\)\\///p"', returnStdout: true).trim()
                        echo "Two folders found: ${folderName}"
                    } 
                    else {
                        error "Unexpected number of folders found: ${folders}"
                    }
                    env.FOLDER_NAME = folderName
                }
            }
        }
        stage('Build for Windows') {
            steps {
                dir("${env.FOLDER_NAME}") {
                    script {
                        sh '''
                          x86_64-w64-mingw32.static-qmake-qt5;
                          make clean;
                          x86_64-w64-mingw32.static-qmake-qt5 CONFIG+=release;
                          make;
                        '''
                    }
                }
            }
        }
        stage('Deploy for Windows') {
            steps {
                dir("${env.FOLDER_NAME}") {
                    script {
                        def exe = sh(script: 'cd release && find . -name "*.exe" -type f | head -n 1', returnStdout: true).trim()
                        echo "EXE: ${exe}"
                        def branchName = env.BRANCH_NAME
                        sh "make clean"
                        sh "rm -r release"
                        sh "rm -r debug"
                    }
                }
            }   
        }
        stage('Build for Linux') {  
            steps {
                dir("${env.FOLDER_NAME}") {
                    script {
                        sh '''
                          qmake;
                          make clean;
                          qmake CONFIG+=release;
                          make;
                        '''
                    }
                }
            }
        }    
        stage('Deploy for Linux') {
            steps {
                dir("${env.FOLDER_NAME}") {
                    script {
                        def appImageFiles = sh(script: 'find . -maxdepth 1 -name "*.AppImage"', returnStdout: true).trim()
                        if (appImageFiles) {
                            sh 'rm *.AppImage'
                        }
                        def proFile = sh(script: 'find . -name "*.pro" -type f | head -n 1', returnStdout: true).trim()
                        def applicationName = sh(script: "basename --suffix=.pro ${proFile}", returnStdout: true).trim()
                        echo "Project file name without extension: ${applicationName}"
                        def desktopContent = "[Desktop Entry]\n"+"Type=Application\n"+"Name=${applicationName}\n"+
                        "Comment=QT Application\n"+"Exec=${applicationName}\n"+"Icon=default\n"+"Categories=Utility;\n"                         
                        writeFile file: 'default.desktop', text: desktopContent
                        sh "touch default.png"
                        sh "linuxdeployqt ${applicationName} -appimage --appimage-extract-and-run"
                        sh "make clean"
                        def appImage = sh(script: 'find . -name "*.AppImage" -type f | head -n 1', returnStdout: true).trim()
                        sh "mv ${appImage} ${applicationName}.AppImage"
                        appImage = sh(script: 'find . -name "*.AppImage" -type f | head -n 1', returnStdout: true).trim()
                        echo "AppImage: ${appImage}"
                        def branchName = env.BRANCH_NAME
                    }
                }
            }
        }
    }
}
