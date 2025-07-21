```
I'm new to Sourcetree and have created a mess locally, with 7 ahead commits compared to the origin/master. I want to ignore and remove everything I've done locally and start again by reverting my local repo to the origin/master as it currently stands. How do I do this?

Remark: I know the origin/master is correct since I have another machine next to me which I don't use to do commits and just did a pull from the origin/master, and the local repo is correct on this other machine.
```
           
You can set your current master to match the origin master by:

Check out the master branch. Double click the branch, or open the terminal and type git checkout master

Then reset the branch to origin master. Locate origin/master in the log, right click, click "Reset current branch to this commit" and select hard from the dialog that comes up. Or use the command git reset --hard origin/master

use ```git pull --rebase```
or  ```git rebase --abort ``