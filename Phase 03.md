Phase 3: Conflict Resolution (Merge & Rebase)
Create conflicting changes: edit the same file/line on main and on a feature branch (commit both).
<img width="1115" height="410" alt="image" src="https://github.com/user-attachments/assets/797604c1-99fe-4d96-a23b-2b584aebf59f" />

Merge the feature branch into main → handle the resulting conflict manually.
<img width="1111" height="387" alt="image" src="https://github.com/user-attachments/assets/a2874f82-f306-4d94-ade0-beb873c9b5bc" />


Abort a merge that has conflicts.
<img width="777" height="265" alt="image" src="https://github.com/user-attachments/assets/4385f62e-0311-4b32-9ea1-3486bb29f81c" />
<img width="1083" height="382" alt="image" src="https://github.com/user-attachments/assets/1c475f77-4a94-4e95-b323-42e9c96ffb93" />



            (If need to edit for keeping main branch code or local branch code)
            $ git merge feature-A
            Auto-merging L 4/Intern/conflict.txt
            CONFLICT (content): Merge conflict in L 4/Intern/conflict.txt
            Automatic merge failed; fix conflicts and then commit the result.
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git merge --abort
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add "L 4/Intern/conflict.txt"
            warning: could not open directory 'L 4/Intern/L 4/Intern/': No such file or directory
            fatal: pathspec 'L 4/Intern/conflict.txt' did not match any files
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git rebase --continue
            Successfully rebased and updated refs/heads/feature-rebase.
            (.venv) 

            vim terminal asle --->  esc -> :wq -> enter

Set up another conflict scenario, then rebase the feature branch onto main instead → resolve conflict during rebase.

<img width="1108" height="442" alt="image" src="https://github.com/user-attachments/assets/2c826eb3-dac2-401d-b662-0eff1077ba67" />

Use VS Code to visually resolve at least one conflict (markers + staging + continue).
<img width="1040" height="307" alt="image" src="https://github.com/user-attachments/assets/6fb6349b-3b90-4875-8b0e-ba3429526ce5" />
<img width="1142" height="283" alt="image" src="https://github.com/user-attachments/assets/1edf0f19-d64f-46dd-8694-a0129d60e8a5" />
<img width="926" height="342" alt="image" src="https://github.com/user-attachments/assets/aeb5e1a4-b238-4977-9fd6-d56f1ed5e852" />

Create a branch, make several commits, then merge it into main → observe merge commit in history.

User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
$ git log --oneline --graph
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
| * | 30356d3 change from a
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
| * | 30356d3 change from a
| * | c6cc8b0 change from a
| * | 188a786 feature changed
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
| * | 30356d3 change from a
| * | c6cc8b0 change from a
| * | 188a786 feature changed
| * | 71e41ab modified features
| * | cff3974 feature modified
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
| * | 30356d3 change from a
| * | c6cc8b0 change from a
| * | 188a786 feature changed
| * | 71e41ab modified features
| * | cff3974 feature modified
* | |   8254bd1 Merge pull request #15 from saiefadnan/adnan
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
| * | 30356d3 change from a
| * | c6cc8b0 change from a
| * | 188a786 feature changed
| * | 71e41ab modified features
| * | cff3974 feature modified
* | |   8254bd1 Merge pull request #15 from saiefadnan/adnan
|\ \ \
:...skipping...
* 873d8b6 (HEAD) Feature commit for rebase
* 208bbb3 (main) Main-e notun change
* c1dfbbf Main commit for rebase
*   9f7c93b Resolved conflict manually
|\
| * 74e56b6 (feature-three) Commit 2 on feature-three
* | bcfe124 Commit 3 on main to diverge
|/
* 8383ed5 Commit 1 on main
* ea2362e (feature-two) Commit on feature-two
* c38eebb Commit on main
* 70d1d83 (feature-one) change in feature
* cfb3ceb change in main
* 96575b3 base commit
*   1268430 Merge pull request #18 from saiefadnan/branch-b
|\
| *   2ecf2c4 Merge branch 'main' into branch-b
| |\
| |/
|/|
* |   8874471 Merge pull request #17 from saiefadnan/branch-a
|\ \
| * | 220d053 change from branch-a
| * | 30356d3 change from a
| * | c6cc8b0 change from a
| * | 188a786 feature changed
| * | 71e41ab modified features
| * | cff3974 feature modified
* | |   8254bd1 Merge pull request #15 from saiefadnan/adnan
|\ \ \
| * | | cc95b0b Update Phase05.md
| * | | 6650e21 Update Phase05.md
| * | | 5dec0ed Update Phase05.md
| * | | 36f543a Add image for branch reset instructions
| * | | be038c3 Add images and content for Phase 04 instructions
| * | | 8d74b7a Update Phase04.md
| * | | 37bb6c6 Update Phase04.md
| * | | 3084ec0 Add images for amending the last commit
| * | | d3d596b Update Phase04.md
| * | | 9a052e1 Update Phase04.md
| * | | 6f7d654 Update Phase05.md
| * | | 863df0b Fix typo in Final Challenge section header
| * | | c285a77 Document team flow simulation and capstone challenge
| * | | 7729c1a Update Phase04.md
| * | | 9236d7e Update Phase03.md
* | | |   52847f7 Merge pull request #16 from saiefadnan/branch-a
|\ \ \ \
| | |/ /
| |/| |
| * | | 07f7116 new features
| * | | 7d4f5b8 changes in branch-a
|/ / /
* | |   daf5c28 Merge branch 'branch-b'
|\ \ \
* | | | fdfbe14 feature added
| | | *   48822f8 conflict resolved
| | | |\
| | | | * ca63ba4 change from b
| | |_|/
| |/| |
| | | * c14f69d change from b
| | |/
| |/|
| * | ba68989 feature added
|/ /
* |   aa4d0c4 resolving issues
|\ \
| * | e482220 this is a feature from branch a
| * | d942f18 4th line from feature
| * |   acf5c3b (origin/adnan_login-signup_feature) Merge branch 'main' into adnan_login-signup_feature
| |\ \
| * | | c2a225b change in 2nd line
| * | | 256a211 this is c3
| * | | 097f3a6 this is c2
| * | | e8a225c this is c1
| * | | 5617ece adding feature c
| * | | aae6228 adding feature b
| * | | 47e3623 adding feature a
* | | | 3220063 tracking untracked files
* | | | 065bacd some changes
* | | | cbd2ae8 test feature d and e added
* | | | dc08283 test feature c
* | | | 2eeb28a test feature b
* | | | c6bc989 test feature a
* | | | 307c6ec 4th line from main
| |/ /
|/| |
* | |   8955262 Merge branch 'adnan' of github.com:saiefadnan/github-tutorial
|\ \ \
| | |/
| |/|
| * | 1008ec4 Update Phase03.md
| * | bd8cf10 Update Phase03.md
| * | 116545f Update Phase03.md
| * | 46ea781 Update Phase02.md
| * | 03d0c06 Update Phase02.md
| * | 5b6e3d5 Update Phase02.md
| * | 6dd2464 Update Phase02.md
| * | 9ac4f00 Update Phase02.md
| * | bf18bd0 Update Phase01.md
| * | 0cbc29f Update Phase02.md
| * | 09af1d2 Update Phase02.md
* | | 6d5b5d0 change in 2nd line
| |/
|/|
* | 8b6acd1 Delete latestfile.txt
* | 7051b57 Delete latest_3.txt
* | 5d5884b adding latest3
* | dc7bf3f adding latest2
* | c44c3c0 adding latest1
* |   21caaea Merge branch 'main' of github.com:saiefadnan/github-tutorial
|\ \  
| * | bd08f68 Create latestfile.txt
* | | 56126ca Merge branch 'main' of github.com:saiefadnan/github-tutorial
|\| |
| * | f6ac618 Delete latestfile.txt
| * | 7048836 Create latestfile.txt
| |/
* / 7af1cca file adding on a old branch
|/
*   af020f6 Merge pull request #14 from saiefadnan/new_branch
|\
| * 858cd75 adding all .md files
|/
*   c58ba13 Merge pull request #13 from saiefadnan/saiefadnan-patch-9
|\
| * 7d058e5 Create Phase02.md
|/
*   b960c4e Merge pull request #12 from saiefadnan/saiefadnan-patch-8
|\
| * 6e33d4a Update Phase01.md
* |   a0fe0d9 Merge pull request #11 from saiefadnan/example
|\ \
| |/
|/|
| * 1b25c22 commit example.txt
| * af087e2 this is another practice file
* |   1846762 Merge pull request #10 from saiefadnan/saiefadnan-patch-7
|\ \
| |/
|/|
| * 693404e Update Phase01.md
* |   30d6fd3 Merge pull request #9 from saiefadnan/my_new_branch
|\ \
| |/
|/|
| *   f3ee6d6 Merge branch 'main' of github.com:saiefadnan/github-tutorial
| |\
| |/
|/|
* |   4f2a4a4 Merge pull request #8 from saiefadnan/saiefadnan-patch-6
|\ \
| * | 47423db Update Phase01.md
|/ /
| * 895d299 commiting staged file
|/
*   87d4ac4 Merge pull request #7 from saiefadnan/saiefadnan-patch-5
|\
| * 4d0003a Update Phase01.md
|/
*   1e8b197 Merge pull request #6 from saiefadnan/saiefadnan-patch-4
|\
| * d24ff30 Update Phase01.md
|/  
*   66c792e Merge pull request #5 from saiefadnan/saiefadnan-patch-3
|\
| * a056ff2 Update and rename README.md to Phase01.md
|/
* 12ce1b4 Initial commit
(END)



Do the same scenario again but rebase instead → compare the history graphs.
