#/bin/bash

# git add '*.cbp'
# git add '*.h'
# git add '*.cpp'
# git add '*.pro'
# git add '*.doc'
# git add '*.docx'
# git add '*.txt'
# git add '*.cbp'
# git add '*.ico'
# git add '*.qrc'
# git add '*.zip'
git add *

git commit -m "Update "$(date +"%y-%m-%d-%T")

git remote add origin https://github.com/46ccac1474d000676430445ffc4b160a/Algo.git

echo '46ccac1474d000676430445ffc4b160a'

git push -u origin master