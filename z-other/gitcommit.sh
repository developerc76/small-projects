#/usr/bin/env bash

echo "Repo Name (Case Sensitive): "
read repo
cd $repo
echo "Fetching code from repository..."
git fetch
git pull .
git add -A
echo "Commit message: "
read commitmessage
git commit -m "$commitmessage"
echo "Branch to commit to: "
read branch
git push origin "$branch"