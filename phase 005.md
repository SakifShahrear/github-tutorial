Phase 5: Team Simulation & GitHub Integration
Simulate team flow: create two feature branches, make changes on each.
          User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
          $ git checkout -b feature-B
          Switched to a new branch 'feature-B'
          (.venv) 
          User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
          $ git checkout -b feature-B
          fatal: a branch named 'feature-B' already exists
          (.venv) 
          User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
          $ git checkout -b feature-C
          Switched to a new branch 'feature-C'
          (.venv) 
          User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
          $ echo "Feature B work" > feature_b.txt
          (.venv) 
          User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
          $ git add . && git commit -m "Add feature B"
          warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it
          [feature-C 5cebba4] Add feature B
           1 file changed, 1 insertion(+)
           create mode 100644 L 4/Intern/feature_b.txt
          (.venv) 
As "team lead": merge both features into main via command line (two separate merges).
            $ git checkout main
            Switched to branch 'main'
            Your branch and 'origin/main' have diverged,
            and have 11 and 5 different commits each, respectively.
              (use "git pull" to merge the remote branch into yours)
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout -b feature-B
            Switched to a new branch 'feature-B'
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout -b feature-B
            fatal: a branch named 'feature-B' already exists
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout -b feature-C
            Switched to a new branch 'feature-C'
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ echo "Feature B work" > feature_b.txt
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
            fatal: a branch named 'feature-B' already exists
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout -b feature-C
            Switched to a new branch 'feature-C'
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ echo "Feature B work" > feature_b.txt
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout -b feature-C
            Switched to a new branch 'feature-C'
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ echo "Feature B work" > feature_b.txt
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
            $ git checkout -b feature-C
            Switched to a new branch 'feature-C'
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ echo "Feature B work" > feature_b.txt
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ echo "Feature B work" > feature_b.txt
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add . && git commit -m "Add feature B"
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
             create mode 100644 L 4/Intern/feature_b.txt
            warning: in the working copy of 'L 4/Intern/feature_b.txt', LF will be replaced by CRLF the next time Git touches it     
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
             create mode 100644 L 4/Intern/feature_b.txt
            [feature-C 5cebba4] Add feature B
             1 file changed, 1 insertion(+)
             create mode 100644 L 4/Intern/feature_b.txt
             create mode 100644 L 4/Intern/feature_b.txt
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout main
            Switched to branch 'main'
            Your branch and 'origin/main' have diverged,
            and have 11 and 5 different commits each, respectively.
              (use "git pull" to merge the remote branch into yours)
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git merge feature-A
            Auto-merging L 4/Intern/conflict.txt
            CONFLICT (content): Merge conflict in L 4/Intern/conflict.txt
            Automatic merge failed; fix conflicts and then commit the result.
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git merge feature-A
            fatal: You have not concluded your merge (MERGE_HEAD exists).
            Please, commit your changes before you merge.
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git merge --abort
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git add conflict.txt
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git commit -m "done"
            [main a5acfb9] done
             1 file changed, 1 insertion(+)
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
            $ git checkout main
            Already on 'main'
            Your branch and 'origin/main' have diverged,
            and have 12 and 5 different commits each, respectively.
              (use "git pull" to merge the remote branch into yours)
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase|REBASE 2/2)
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
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase)
            $ git checkout main
            Switched to branch 'main'
            Your branch and 'origin/main' have diverged,
            and have 12 and 5 different commits each, respectively.
              (use "git pull" to merge the remote branch into yours)
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main)
            $ git merge feature-A
            Auto-merging L 4/Intern/conflict.txt
            CONFLICT (content): Merge conflict in L 4/Intern/conflict.txt
            Automatic merge failed; fix conflicts and then commit the result.
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main|MERGING)
            $ git add "L 4/Intern/conflict.txt"
            warning: could not open directory 'L 4/Intern/L 4/Intern/': No such file or directory
            fatal: pathspec 'L 4/Intern/conflict.txt' did not match any files
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main|MERGING)
            $ git add conflict.txt"
            > 
            > 
            > ^C
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main|MERGING)
            $ git add "L 4/Intern/conflict.txt"
            warning: could not open directory 'L 4/Intern/L 4/Intern/': No such file or directory
            fatal: pathspec 'L 4/Intern/conflict.txt' did not match any files
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main|MERGING)
            $ git add conflict.txt
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main|MERGING)
            $ git commit -m "Merged feature-A into main and resolved conflicts"
            [main 06775f2] Merged feature-A into main and resolved conflicts
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main)
            $ git merge feature-A
            Already up to date.
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main)
            $ git merge feature-B
            Already up to date.
            (.venv)
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main)
            $
As "developer": after leader merged, update your local branch and push new work.
            $ git pull origin main
            From https://github.com/saiefadnan/github-tutorial
             * branch            main       -> FETCH_HEAD
            Merge made by the 'ort' strategy.
             auth.txt | 4 ++++
             1 file changed, 4 insertions(+)
             create mode 100644 auth.txt
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (main)
            $ git checkout feature-rebase
            Switched to branch 'feature-rebase'
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase)
            $ git rebase main
            Successfully rebased and updated refs/heads/feature-rebase.
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase)
            $ echo "Developer's new task" > dev_work.txt
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase)
            $ git add .
            warning: in the working copy of 'L 4/Intern/dev_work.txt', LF will be replaced by CRLF the next time Git touches it
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase)
            $ git commit -m "Developer updated new work"
            [feature-rebase c5781d2] Developer updated new work
             1 file changed, 1 insertion(+)
             create mode 100644 L 4/Intern/dev_work.txt
            (.venv) 
            User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (feature-rebase)
            $ git push origin feature-rebase
            Enumerating objects: 79, done.
            Counting objects: 100% (79/79), done.
            Delta compression using up to 8 threads
            Compressing objects: 100% (36/36), done.
            Writing objects: 100% (77/77), 14.15 KiB | 762.00 KiB/s, done.
            Total 77 (delta 19), reused 0 (delta 0), pack-reused 0
            remote: Resolving deltas: 100% (19/19), completed with 1 local object.
            remote:
            remote: Create a pull request for 'feature-rebase' on GitHub by visiting:
            remote:      https://github.com/saiefadnan/github-tutorial/pull/new/feature-rebase
            remote:
            To https://github.com/saiefadnan/github-tutorial.git
             * [new branch]      feature-rebase -> feature-rebase
            (.venv) 
Create a pull request from one feature branch to main on GitHub → merge it through the web interface.

Resolve a small conflict directly in the GitHub pull request interface.

Simulate a disaster: commit junk to main → recover using reset techniques.

Full end-to-end challenge: Start fresh day → sync → work on feature → get "team" update on main → resolve conflict → clean history → create PR → merge.
