# repos="url-shortcut django-app-deployment stupid-app Algorithm simple-calculator"

repo=$1
git remote add --fetch $repo git@gitlab.com:Magiskb0Y/$repo
git merge --allow-unrelated-histories $repo/master
mkdir $repo
