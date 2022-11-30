echo "your wish is my command"
echo $1
echo $2
if [ -z "$1" ] | [ -z "$2" ]
then
	echo "Enter in the following format:"
	echo "./push2Git.sh <reponame> < message >"
	exit
fi

git remote add origin_name https://github.com/Supriya-Bhide/$2.git
git add .
git commit -m "$1"
git push -u origin_name main
