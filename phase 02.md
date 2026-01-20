Phase 2: Branching & Daily Sync Workflow
Create a new feature branch from main.
      git branch sakif1
Rename your current branch to something more descriptive.
      git branch -m sakif(m means modify je branch a achi oi branch name change hobe)
Delete an old, merged branch (not the current one).
        git branch -D sakif(not marged) if marged d replaced by D
        remote branch -> git push origin --delete sakif (Remote server a ache) ( d for delete)
Simulate a full daily start: update main from remote, switch to your feature branch, update your branch with latest main.
          git checkout main
          git pull origin main             # রিমোট থেকে মেইন আপডেট করা
          git checkout sakif
          git merge main                   # মেইনের লেটেস্ট কোড ফিচারে আনা
Make 2–3 commits on your feature branch.

Intentionally work on an outdated branch (skip update step), try to push → observe failure.

Fix the outdated branch so you can successfully push (use force if needed).
        git push origin sakif --force
Repeat the full sync → work → update → push cycle 3 times in a row.
