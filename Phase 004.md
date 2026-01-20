Phase 4: Recovery & History Cleanup
Accidentally commit changes to the wrong branch → move those changes to the correct branch.
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git branch correct-branch
        (.venv) 
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git reset --hard HEAD~1
        HEAD is now at 208bbb3 Main-e notun change
        (.venv) 
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git checkout correct-branch
        Previous HEAD position was 208bbb3 Main-e notun change
        Switched to branch 'correct-branch'
        (.venv) 
Amend the very last commit (add forgotten change + fix message).
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git add forgotten-file.txt
        (.venv) 
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git commit --amend -m "new mgs"
        [correct-branch 1e871de] new mgs
         Date: Mon Jan 19 23:04:55 2026 +0600
         2 files changed, 5 insertions(+)
         create mode 100644 L 4/Intern/forgotten-file.txt
        (.venv)
Undo the last commit but keep the changes in working directory/staged area.
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git reset --soft HEAD~1
        (.venv) 
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git reset HEAD~1
        Unstaged changes after reset:
        M       L 4/Intern/conflict.txt
        (.venv) 
        User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
        $ git reset --hard HEAD~1
        HEAD is now at 9f7c93b Resolved conflict manually
        (.venv) 
Completely undo and discard the last commit + changes.
        $ git reset --hard HEAD~1
        HEAD is now at bcfe124 Commit 3 on main to diverge
        (.venv)
Create a branch with 5 small, related commits → use interactive rebase to squash them into 2–3 cleaner commits.

        Pick one specific commit from another branch and apply it to your current branch.
        70197c0 (origin/sakif) Create phase 04
        ea9b678 Update and rename Phase 01.md to Phase 03.md
        63f1c1c (feature-rebase) Feature-e conflict create korlam
        208bbb3 (main) Main-e notun change
        b5a40be Feature commit for rebase
        c1dfbbf Main commit for rebase
        9f7c93b (HEAD -> correct-branch) Resolved conflict manually
        bcfe124 Commit 3 on main to diverge
        74e56b6 (feature-three) Commit 2 on feature-three
        8383ed5 Commit 1 on main
        ea2362e (feature-two) Commit on feature-two
        c38eebb Commit on main
        70d1d83 (feature-one) change in feature
        cfb3ceb change in main
        96575b3 base commit
        8a6fba9 Create Phase 01.md
        cc95ffb (origin/adnan) commit resolved on Phase03.md
        56057a2 Update Phase05.md
        cae9230 Update Phase05.md
        49bb2a6 (origin/main) Merge pull request #20 from saiefadnan/branch-a
        3e433fe Update Phase05.md
        8a3751a Update Phase05.md
        8486fe3 Update Phase05.md
        962d336 Update Phase05.md
        1b09aa8 Update Phase05.md
        63028a1 Update Phase05.md
        a5f3a11 (origin/branch-a) login done
        07c08c4 Merge pull request #19 from saiefadnan/branch-b
        8d95db0 (origin/branch-b) Merge branch 'branch-b' of github.com:saiefadnan/github-tutorial into branch-b
        7a9e3d8 security done
        b1d1bb1 (sakif) a
        (.venv) 
Reset your branch to an earlier commit (keep changes in working directory).
        $ git reset HEAD~1
        Unstaged changes after reset:
        M       L 4/Intern/conflict.txt
        (.venv) 
Reset your branch to an earlier commit and discard all later changes completely.
        $ git reset --hard HEAD~1
        HEAD is now at 8383ed5 Commit 1 on main
        (.venv)
        
