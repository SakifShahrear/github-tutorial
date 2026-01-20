# Cherry-Pick এবং Rebase - সম্পূর্ণ বাংলা গাইড

## 🎯 সূচিপত্র

1. [Cherry-Pick কী এবং কেন?](#cherry-pick)
2. [Rebase কী এবং কেন?](#rebase)
3. [Merge vs Rebase পার্থক্য](#merge-vs-rebase)
4. [Interactive Rebase](#interactive-rebase)
5. [Cherry-Pick vs Rebase - কখন কোনটা?](#comparison)
6. [Best Practices এবং Golden Rules](#best-practices)
7. [Hands-on Practice Exercises](#practice)

---

## 🍒 Cherry-Pick কী?

**সহজ বাংলায়:** অন্য branch থেকে **নির্দিষ্ট একটি বা কয়েকটি commit** বেছে নিয়ে আপনার বর্তমান branch-এ কপি করা। যেমন গাছ থেকে পছন্দের চেরি তুলে নেওয়া!

### 🤔 কেন Cherry-Pick করবেন?

**Scenario 1: Useful Commit কিন্তু পুরো Branch না**

```bash
# আপনার feature branch-এ একটি bug fix করেছেন
# কিন্তু পুরো feature ready না, শুধু bug fix main-এ দরকার

Feature Branch:
- abc123d fix: critical security bug  ← এটা দরকার!
- def456g feat: half-done new feature  ← এটা ready না

# Solution: শুধু bug fix cherry-pick করুন!
```

**Scenario 2: Wrong Branch-এ Commit**

```bash
# ভুলে main-এ commit করে ফেলেছেন
# সেটা feature branch-এ নিয়ে যেতে হবে
```

**Scenario 3: Hotfix Multiple Branches-এ**

```bash
# Production-এ bug পেয়েছেন
# Fix main, develop, release সব branches-এ দরকার
```

### 📝 Cherry-Pick কিভাবে করবেন?

**Basic Cherry-Pick:**

```bash
# Step 1: যে commit চান তার SHA খুঁজুন
git log --oneline feature-branch
# Output:
# abc123d fix: resolve critical bug  ← এটা চাই!
# def456g feat: new feature work
# ghi789j refactor: code cleanup

# Step 2: যে branch-এ নিতে চান সেখানে যান
git checkout main

# Step 3: Cherry-pick করুন
git cherry-pick abc123d

# Done! শুধু bug fix এসেছে
```

**একাধিক Commits Cherry-Pick:**

```bash
# Method 1: একসাথে 3টি commits
git cherry-pick abc123d def456g ghi789j

# Method 2: Range cherry-pick
git cherry-pick abc123d^..ghi789j
# abc123d থেকে ghi789j পর্যন্ত সব commits
```

### ⚠️ Cherry-Pick Conflict হলে কী করবেন?

```bash
# Cherry-pick করার সময় conflict
git cherry-pick abc123d

# Output:
# error: could not apply abc123d... fix bug
# hint: after resolving the conflicts, mark them with
# hint: 'git add <paths>' and run 'git cherry-pick --continue'

# Step 1: Conflict resolve করুন
nano conflicted-file.txt
# Markers (<<<, ===, >>>) মুছে fix করুন

# Step 2: Resolved file add করুন
git add conflicted-file.txt

# Step 3: Continue করুন
git cherry-pick --continue

# অথবা বাতিল করতে চাইলে
git cherry-pick --abort
```

### 💡 Cherry-Pick Tips

```bash
# Tip 1: Commit message edit করে cherry-pick
git cherry-pick abc123d --edit

# Tip 2: Cherry-pick কিন্তু commit করবেন না (পরে করবেন)
git cherry-pick abc123d --no-commit

# Tip 3: Author information রাখুন
git cherry-pick abc123d -x
# Commit message-এ যোগ হবে: "(cherry picked from commit abc123d)"

# Tip 4: Multiple commits এর মধ্যে skip করতে
git cherry-pick --skip
```

---

## 🔄 Rebase কী?

**সহজ বাংলায়:** আপনার branch-এর commits গুলো তুলে নিয়ে অন্য একটি branch-এর **উপরে নতুন করে বসানো**। এতে commit history **সোজা লাইনে (linear)** হয়।

### 🎨 Visual তুলনা: Merge vs Rebase

**Merge (Branch থাকে):**

```
Before Merge:
      C---D---E  (feature)
     /
A---B           (main)

After Merge:
      C---D---E  (feature)
     /         \
A---B-----------F  (main)
                ↑ Merge commit

History: A → B → C → D → E → F (branching দেখায়)
```

**Rebase (Linear হয়):**

```
Before Rebase:
      C---D---E  (feature)
     /
A---B---F---G   (main)

After Rebase:
A---B---F---G---C'---D'---E'  (feature)
                ↑
              main এর উপরে বসানো

History: A → B → F → G → C' → D' → E' (straight line)
```

### 🤔 কেন Rebase করবেন?

**কারণ 1: Clean History**

```bash
# Merge করলে:
* Merge branch 'feature' into main
* feat: add feature
* fix: typo
* Merge branch 'main' into feature
* feat: another feature
* Merge branch 'feature' into main
# অনেক merge commits, messy!

# Rebase করলে:
* feat: another feature
* feat: add feature
# Clean, readable!
```

**কারণ 2: Feature Branch Update**

```bash
# Main branch update হয়েছে, আপনার feature outdated
# Merge করলে: অনেক merge commits
# Rebase করলে: feature main-এর উপরে বসে যাবে, clean!
```

### 📝 Rebase কিভাবে করবেন?

**Basic Rebase:**

```bash
# Scenario: Feature branch main থেকে outdated
# Main-এ নতুন commits এসেছে

# Step 1: Feature branch-এ যান
git checkout feature-branch

# Step 2: Main-এর উপরে rebase করুন
git rebase main

# Done! Feature branch এখন main-এর উপরে
```

**Rebase with Update:**

```bash
# পুরো workflow (Daily sync)
# Step 1: Main update করুন
git checkout main
git pull origin main

# Step 2: Feature branch rebase করুন
git checkout feature-branch
git rebase main

# Step 3: যদি conflict না থাকে, push করুন
git push origin feature-branch

# যদি already push করা থাকে, force push লাগবে
git push --force-with-lease origin feature-branch
```

### ⚠️ Rebase Conflict হলে কী করবেন?

```bash
# Rebase করার সময় conflict
git rebase main

# Output:
# CONFLICT (content): Merge conflict in file.txt
# error: could not apply abc123d... your commit message

# Step 1: Conflict resolve করুন
git status  # Conflicted files দেখুন
nano file.txt  # Conflict fix করুন

# Step 2: Resolved files add করুন
git add file.txt

# Step 3: Rebase continue করুন
git rebase --continue

# যদি আরও conflicts থাকে, steps repeat করুন

# Rebase বাতিল করতে চাইলে
git rebase --abort
```

### 🚨 Rebase করার পর Push করা

```bash
# যদি আগে কখনো push না করে থাকেন
git push origin feature-branch

# যদি আগে push করা থাকে (rebase history change করেছে)
git push --force-with-lease origin feature-branch

# ⚠️ সাবধান!
# --force শুধু নিজের branch-এ ব্যবহার করুন
# Shared branch-এ NEVER!
```

---

## 🔀 Merge vs Rebase - বিস্তারিত তুলনা

| Feature              | Merge                         | Rebase                        |
| -------------------- | ----------------------------- | ----------------------------- |
| **History**          | Branching (merge commits আছে) | Linear (straight line)        |
| **Merge Commit**     | ✅ তৈরি হয়                   | ❌ হয় না (fast-forward)      |
| **Original Commits** | ✅ Preserve করে               | ❌ Re-write করে (নতুন SHA)    |
| **Readability**      | 🔴 Complex graph              | 🟢 Simple, easy to follow     |
| **Safety**           | 🟢 নিরাপদ (history না বদলায়) | 🔴 Dangerous (history বদলায়) |
| **Use Case**         | Main/shared branches          | Personal feature branches     |
| **Team Work**        | 🟢 Safe for shared work       | 🔴 Risky if others use branch |

### কখন Merge করবেন?

✅ **Merge Use Cases:**

```bash
# 1. Main/Master branches
git checkout main
git merge feature-branch

# 2. Team-এর shared branches
git checkout develop
git merge feature-team

# 3. Important milestones track করতে
git merge release-v1.0

# 4. Branch relationship দেখাতে চান
git merge feature-a feature-b
```

### কখন Rebase করবেন?

✅ **Rebase Use Cases:**

```bash
# 1. Personal feature branch update
git checkout my-feature
git rebase main

# 2. PR তৈরির আগে history clean করা
git rebase -i HEAD~5

# 3. Local commits organize করা
git rebase -i main

# 4. Feature branch-এ main-এর latest changes নেওয়া
git rebase main
```

### কখন Rebase করবেন না? 🚫

❌ **NEVER Rebase:**

```bash
# 1. Public/Shared branches
git checkout main
git rebase feature  # ❌ DON'T!

# 2. অন্যরা ব্যবহার করছে এমন branch
git checkout team-feature
git rebase main  # ❌ Team-এর problem হবে!

# 3. Already pushed এবং others pulled করেছে
git rebase main  # ❌ Others-এর সমস্যা!
```

---

## 🎯 Interactive Rebase - সবচেয়ে Powerful!

**বাংলায়:** একাধিক commits একসাথে edit করা - squash, reword, reorder, delete, edit!

### 📝 Interactive Rebase Commands

```bash
# শেষ 5টি commits edit করতে
git rebase -i HEAD~5

# Specific commit থেকে শুরু করতে
git rebase -i abc123d
```

**Editor খুলবে এরকম:**

```bash
pick abc123d First commit
pick def456g Second commit
pick ghi789j Third commit
pick jkl012m Fourth commit
pick mno345p Fifth commit

# Commands:
# p, pick   = commit ব্যবহার করুন (no change)
# r, reword = commit ব্যবহার করুন কিন্তু message edit করুন
# e, edit   = commit edit করুন (code change করতে পারবেন)
# s, squash = commit আগেরটার সাথে মিশিয়ে দিন (message রাখুন)
# f, fixup  = commit আগেরটার সাথে মিশিয়ে দিন (message ফেলে দিন)
# d, drop   = commit সম্পূর্ণ মুছে ফেলুন
# x, exec   = shell command run করুন
```

### 🔧 Interactive Rebase Use Cases

**Use Case 1: Squash (একসাথে মিশানো)**

```bash
# Before: 5টি messy commits
abc123d WIP: start feature
def456g WIP: continue work
ghi789j fix typo
jkl012m WIP: almost done
mno345p final touches

# Interactive rebase
git rebase -i HEAD~5

# Editor-এ পরিবর্তন করুন:
pick abc123d WIP: start feature
fixup def456g WIP: continue work
fixup ghi789j fix typo
pick jkl012m WIP: almost done
fixup mno345p final touches

# Save and close

# After: শুধু 2টি clean commits!
abc123d feat: implement core feature functionality
jkl012m feat: complete feature with polish
```

**Use Case 2: Reword (Message পরিবর্তন)**

```bash
# Before:
abc123d fix bug  # খারাপ message

# Interactive rebase
git rebase -i HEAD~1

# Editor-এ:
reword abc123d fix bug

# Save করলে নতুন editor আসবে message change করতে
# Change to: "fix: resolve login timeout issue"

# After:
abc123d fix: resolve login timeout issue  # ভালো message!
```

**Use Case 3: Reorder (Commits এর ক্রম পরিবর্তন)**

```bash
# Before:
abc123d feat: add feature A
def456g docs: update README
ghi789j feat: add feature B

# Interactive rebase
git rebase -i HEAD~3

# Editor-এ order পরিবর্তন করুন:
pick abc123d feat: add feature A
pick ghi789j feat: add feature B  # উপরে নিলাম
pick def456g docs: update README  # নিচে নিলাম

# After: Features একসাথে, docs শেষে
```

**Use Case 4: Edit (Commit-এ code পরিবর্তন)**

```bash
# একটি পুরানো commit-এ code যোগ করতে চান

git rebase -i HEAD~3

# Editor-এ:
edit abc123d feat: add feature
pick def456g fix: bug fix
pick ghi789j docs: update

# Save করলে rebase stop করবে abc123d-তে

# এখন code edit করুন
echo "forgotten code" >> file.txt
git add file.txt
git commit --amend --no-edit

# Continue করুন
git rebase --continue
```

**Use Case 5: Drop (Commit মুছে ফেলা)**

```bash
# Before:
abc123d feat: good feature
def456g debug: console.log added  ← মুছে ফেলতে চাই
ghi789j feat: another feature

# Interactive rebase
git rebase -i HEAD~3

# Editor-এ:
pick abc123d feat: good feature
drop def456g debug: console.log added  # অথবা এই line-ই মুছে ফেলুন
pick ghi789j feat: another feature

# After: debug commit চলে গেছে!
```

---

## 🎯 Cherry-Pick vs Rebase - কখন কোনটা?

### Decision Tree

```
আপনার সমস্যা কী?
│
├─ একটি/কয়েকটি specific commit copy করতে চাই
│  └─ 🍒 Cherry-Pick ব্যবহার করুন
│
├─ পুরো branch-এর history clean করতে চাই
│  └─ 🔄 Rebase ব্যবহার করুন
│
├─ Feature branch main-এর সাথে update করতে চাই
│  ├─ Personal branch? → 🔄 Rebase
│  └─ Shared branch? → 🔀 Merge
│
├─ অনেকগুলো commits একসাথে করতে চাই
│  └─ 🔄 Interactive Rebase (squash)
│
└─ Bug fix multiple branches-এ দরকার
   └─ 🍒 Cherry-Pick করুন প্রতিটিতে
```

### বাস্তব Scenarios

| Scenario                        | Solution                | Command                   |
| ------------------------------- | ----------------------- | ------------------------- |
| Wrong branch-এ commit করেছি     | 🍒 Cherry-Pick          | `git cherry-pick abc123d` |
| Feature branch outdated         | 🔄 Rebase               | `git rebase main`         |
| Hotfix সব branches-এ দরকার      | 🍒 Cherry-Pick          | `git cherry-pick fix-sha` |
| 10টি WIP commits cleanup        | 🔄 Interactive Rebase   | `git rebase -i HEAD~10`   |
| Main-এর নতুন code feature-এ চাই | 🔀 Merge অথবা 🔄 Rebase | নিজের branch? Rebase      |
| Team branch update              | 🔀 Merge (নিরাপদ)       | `git merge main`          |

---

## 💡 Best Practices এবং Golden Rules

### Cherry-Pick Best Practices

**✅ DO:**

```bash
# Specific commits যখন দরকার
git cherry-pick abc123d

# Bug fix duplicate করতে
git cherry-pick security-fix-sha

# Commit message clarify করতে
git cherry-pick abc123d -x
# Message-এ add হয়: "(cherry picked from commit abc123d)"
```

**❌ DON'T:**

```bash
# পুরো branch cherry-pick করবেন না
# এর জন্য merge/rebase আছে

# অতিরিক্ত cherry-pick
# History duplicate এবং confusing হয়
```

### Rebase Best Practices

**✅ DO:**

```bash
# Personal feature branch-এ
git checkout my-feature
git rebase main

# PR তৈরির আগে cleanup
git rebase -i HEAD~5

# Commit message improve
git rebase -i HEAD~3
# reword ব্যবহার করুন
```

**❌ DON'T:**

```bash
# Public/shared branch rebase করবেন না
git checkout main
git rebase feature  # ❌ NEVER!

# অন্যরা ব্যবহার করছে এমন branch
git checkout team-feature
git rebase main  # ❌ Team সমস্যায় পড়বে!

# Push করার পরে rebase
# যদি অন্যরা pull করে থাকে
```

---

## 🚨 Golden Rules

### Rule 1: Public History কখনো Rewrite করবেন না

```bash
# ❌ WRONG - Main branch rebase
git checkout main
git rebase develop

# ✅ RIGHT - Main branch merge
git checkout main
git merge develop
```

### Rule 2: নিজের Branch = Rebase OK, অন্যের Branch = Merge

```bash
# ✅ আপনার personal branch
git checkout my-feature
git rebase main  # OK!

# ❌ Team-এর shared branch
git checkout team-feature
git rebase main  # DON'T!
```

### Rule 3: Cherry-Pick সংযতভাবে ব্যবহার করুন

```bash
# ✅ Good use
git cherry-pick critical-hotfix

# ❌ Bad use - অনেকগুলো commits
git cherry-pick commit1 commit2 commit3 ... commit20
# এর জন্য merge/rebase ভালো
```

### Rule 4: Force Push করার আগে দুইবার চিন্তা করুন

```bash
# ❌ Dangerous
git push --force origin main

# ✅ Safer (যদি remote change থাকে, fail করবে)
git push --force-with-lease origin my-feature

# ✅ Best - নিজের branch-এই শুধু
```

---

## 🏋️ Hands-on Practice Exercises

### Exercise 1: Cherry-Pick Practice

**Setup:**

```bash
# 1. নতুন repo তৈরি
mkdir cherry-pick-practice && cd cherry-pick-practice
git init

# 2. Main branch-এ initial commit
echo "Main file" > main.txt
git add main.txt
git commit -m "initial: create main.txt"

# 3. Branch A তৈরি করুন
git checkout -b branch-a
echo "Feature A" > feature-a.txt
git add feature-a.txt
git commit -m "feat: add feature A"

echo "Bug fix for A" >> feature-a.txt
git add feature-a.txt
git commit -m "fix: resolve bug in feature A"

# 4. Main-এ ফিরে Branch B তৈরি করুন
git checkout main
git checkout -b branch-b
echo "Feature B" > feature-b.txt
git add feature-b.txt
git commit -m "feat: add feature B"
```

**Task:**

```bash
# Branch A-র bug fix Branch B-তে cherry-pick করুন
# (branch-a-র 2nd commit branch-b-তে নিন)

# Solution:
git log branch-a --oneline  # Bug fix SHA copy করুন
# abc123d fix: resolve bug in feature A

git checkout branch-b
git cherry-pick abc123d

# Verify
git log --oneline
```

### Exercise 2: Basic Rebase Practice

**Setup:**

```bash
# 1. নতুন repo
mkdir rebase-practice && cd rebase-practice
git init

# 2. Main branch commits
echo "Version 1" > app.txt
git add app.txt && git commit -m "v1"

echo "Version 2" >> app.txt
git add app.txt && git commit -m "v2"

# 3. Feature branch তৈরি করুন (v1 থেকে)
git checkout HEAD~1  # Go back to v1
git checkout -b feature
echo "Feature work 1" > feature.txt
git add feature.txt && git commit -m "feat: work 1"

echo "Feature work 2" >> feature.txt
git add feature.txt && git commit -m "feat: work 2"
```

**Task:**

```bash
# Feature branch main-এর উপরে rebase করুন

# Solution:
git checkout feature
git rebase main

# Verify - history linear হয়েছে কি না
git log --oneline --graph --all
```

### Exercise 3: Interactive Rebase - Squash Practice

**Setup:**

```bash
# 1. নতুন repo
mkdir squash-practice && cd squash-practice
git init

# 2. অনেকগুলো messy commits তৈরি করুন
echo "Start" > code.js
git add code.js && git commit -m "WIP: start"

echo "More code" >> code.js
git add code.js && git commit -m "WIP"

echo "Fix typo" >> code.js
git add code.js && git commit -m "fix typo"

echo "More work" >> code.js
git add code.js && git commit -m "WIP continue"

echo "Done" >> code.js
git add code.js && git commit -m "done"

# History messy!
git log --oneline
```

**Task:**

```bash
# 5টি commits → 1টি clean commit-এ squash করুন

# Solution:
git rebase -i HEAD~5

# Editor-এ:
pick abc123d WIP: start
fixup def456g WIP
fixup ghi789j fix typo
fixup jkl012m WIP continue
fixup mno345p done

# Message editor-এ:
# feat: implement complete feature

# Verify
git log --oneline  # শুধু 1টি commit!
```

### Exercise 4: Rebase Conflict Resolution

**Setup:**

```bash
# 1. Conflict scenario তৈরি করুন
mkdir conflict-rebase && cd conflict-rebase
git init

# 2. Main branch
echo "Version 1" > shared.txt
git add shared.txt && git commit -m "v1"

# 3. Feature branch (পুরানো base থেকে)
git checkout -b feature
echo "Feature version" > shared.txt
git add shared.txt && git commit -m "feat: feature version"

# 4. Main update (conflict তৈরি করবে)
git checkout main
echo "Main version" > shared.txt
git add shared.txt && git commit -m "main: main version"
```

**Task:**

```bash
# Feature branch rebase করুন এবং conflict resolve করুন

# Solution:
git checkout feature
git rebase main
# CONFLICT!

# Resolve conflict
nano shared.txt
# Choose করুন কোনটা রাখবেন অথবা দুটোই

git add shared.txt
git rebase --continue

# Verify
git log --oneline --graph --all
```

### Exercise 5: Real-World Workflow Simulation

**Scenario:** আপনি একটি feature নিয়ে কাজ করছেন। Main branch update হয়েছে। আপনার history messy। PR তৈরির আগে সব ঠিক করুন।

```bash
# Setup
mkdir real-workflow && cd real-workflow
git init

# Main branch
echo "App v1" > app.js
git add app.js && git commit -m "v1"

# Feature branch start (messy commits)
git checkout -b feature-user-auth
echo "Login" > login.js
git add login.js && git commit -m "WIP login"

echo "More login" >> login.js
git add login.js && git commit -m "continue"

echo "Signup" > signup.js
git add signup.js && git commit -m "WIP signup"

echo "Fix bug" >> login.js
git add login.js && git commit -m "fix"

# Meanwhile, main updated
git checkout main
echo "App v2" >> app.js
git add app.js && git commit -m "v2"

# Your task:
# 1. Feature branch main-এর সাথে update করুন (rebase)
# 2. 4টি messy commits → 2টি clean commits (interactive rebase)
# 3. PR-ready করুন

# Solution:
git checkout feature-user-auth

# Step 1: Update with main
git rebase main

# Step 2: Clean history
git rebase -i HEAD~4

# Editor:
pick abc123d WIP login
fixup def456g continue
pick ghi789j WIP signup
fixup jkl012m fix

# Message editor:
# feat(auth): implement login functionality
# feat(auth): implement signup functionality

# Step 3: Verify and push
git log --oneline --graph --all
git push origin feature-user-auth
```

---

## 📚 আরও শিখুন

### Related Phases:

- **[Phase 3: Conflict Resolution](Phase3_Complete.md)** - Merge এবং Rebase conflicts handle করা
- **[Phase 4: Recovery & History Cleanup](Phase4_Complete.md)** - Advanced history manipulation
- **[Phase 5: Team Simulation](Phase5_Complete.md)** - Real team workflow

### Commands চিট শীট:

**Cherry-Pick:**

```bash
git cherry-pick <commit-sha>              # Single commit
git cherry-pick <sha1> <sha2> <sha3>      # Multiple commits
git cherry-pick <sha1>^..<sha3>           # Range
git cherry-pick --continue                # After conflict
git cherry-pick --abort                   # Cancel
```

**Rebase:**

```bash
git rebase <branch>                       # Basic rebase
git rebase -i HEAD~n                      # Interactive rebase
git rebase --continue                     # After conflict
git rebase --abort                        # Cancel
git rebase --skip                         # Skip current commit
```

**Force Push (সাবধানে!):**

```bash
git push --force-with-lease origin branch # Safer force push
git push --force origin branch            # Dangerous!
```

---

## 🎓 সারসংক্ষেপ

### Cherry-Pick:

- ✅ Specific commits কপি করার জন্য
- ✅ Bug fixes multiple branches-এ apply করতে
- ⚠️ সংযতভাবে ব্যবহার করুন

### Rebase:

- ✅ Clean, linear history চান
- ✅ Personal feature branches update করতে
- ❌ Public/shared branches-এ NEVER!

### Golden Rule:

> **"If in doubt, use MERGE instead of REBASE!"**

---

**Practice করুন, ভুল করুন, শিখুন! 🚀**

Questions? এই topics নিয়ে আরও জানতে চান? জিজ্ঞাসা করুন! 💬
