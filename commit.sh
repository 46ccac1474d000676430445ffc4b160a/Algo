#/bin/bash

git add '*.cbp'
git add '*.h'
git add '*.cpp'
git add '*.pro'
git add '*.doc'
git add '*.docx'
git add '*.txt'
git add '*.cbp'
git add '*.ico'
git add '*.png'
git add '*.qrc'
git add '*.zip'
git add '*.xml'
git add '*.gradle'
git add '*.properties'
git add 'Lab3/Lab3/android/gradlew'
git add '*.bat'
git add '*.jar'
git add '*.sh'

git commit -m "Update "$(date +"%y-%m-%d-%T")

git remote add origin https://github.com/46ccac1474d000676430445ffc4b160a/Algo.git

echo '46ccac1474d000676430445ffc4b160a'

git push -u origin master