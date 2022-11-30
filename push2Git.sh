#Generic [push code]
# echo "your wish is my command"
# echo $1
# echo $2
# if [ -z "$1" ] | [ -z "$2" ]
# then
# 	echo "Enter in the following format:"
# 	echo "./push2Git.sh < message > <reponame>"
# 	exit
# fi

# git remote add origin_name https://github.com/Supriya-Bhide/$2.git
# git add .
# git commit -m "$1"
# git push -u origin_name main

# echo " do you want to clear the screen?[y/n]"
# read -r response
# echo $response
# if ["$response" == "y"] | ["$response" == "Y"]
# then
#     clear
# fi

echo "your wish is my command"
echo $1
if [ -z "$1" ]
then
	echo "Enter in the following format:"
	echo "./push2Git.sh < message >"
	exit
fi

git remote add origin_name https://github.com/Supriya-Bhide/2WayFetchSimulator.git
git add .
git commit -m "$1"
git push -u origin_name main