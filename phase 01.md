Phase 1: Setup & Git Basics
Configure your global Git user name and email.
        git config --global user.name "Sakif Shahrear"
            git config --global user.email "sakifshahrear@email.com"
        
        ## for chacking\*\*
        
            git config --global --list
            $ git config --global --list
            Output:
            user.email=sakifshahrear@gmail.com
            user.name=Sakif Shahrear
            filter.lfs.clean=git-lfs clean -- %f
            filter.lfs.smudge=git-lfs smudge -- %f
            filter.lfs.process=git-lfs filter-process
            filter.lfs.required=true
Create local config overrides (different email) in your practice repo and verify both global & local settings.
            git config user.name "Sakif Shahrear"
               git config user.email "sakifshahrear@gmail.com"
            
            ## for chacking\*\*
            
                git config --list
                $ git config --list
                Output:
                $ git config --list
            
            diff.astextplain.textconv=astextplain
            filter.lfs.clean=git-lfs clean -- %f
            filter.lfs.smudge=git-lfs smudge -- %f
            filter.lfs.process=git-lfs filter-process
            filter.lfs.required=true
            http.sslbackend=openssl
            http.sslcainfo=C:/Program Files/Git/mingw64/ssl/certs/ca-bundle.crt
            core.autocrlf=true
            core.fscache=true
            core.symlinks=false
            pull.rebase=false
            credential.helper=manager
            : ->> ** means there someting under which can't be shown here. for open terminal and type the command only q word.
Remove one global config value, then remove the entire user section.
            git config --global --unset user.email
            git config --global --remove-section user
Make a small file change, stage it, view staged changes only.
            git diff --staged (first git add korte hobe)
             #include <bits/stdc++.h>
                using namespace std;
                +#define int long long
            
                -int main()
                +int32_t main()
                {
                    int n;
                    int x, y, z;
                @@ -9,10 +10,10 @@ int main()
                @@ -9,10 +10,10 @@ int main()
            
                    for (int i = 0; i < n; i++)
                    {
                -        int x;
                +        int x, count=0;
                +        int y;
                        cin >> x;
            
                -        int count = 0;
                        for (int j = 1; j * j <= x; j++)
                        {
                            if (x % j == 0)
                (END)
                # @@ -0,0 +1,36 @@: এর মানে ফাইলটি আগে খালি ছিল, এখন আপনি নতুন ১ থেকে ৩৬ নম্বর লাইন পর্যন্ত কোড যোগ করেছেন।
View all changes (staged + unstaged) compared to last commit.
            git diff ==== শুধুমাত্র সেই পরিবর্তনগুলো যেগুলো এখনো git add করা হয়নি (Unstaged)।
            git diff --staged ==== শুধুমাত্র সেই পরিবর্তনগুলো যেগুলো git add করা হয়েছে (Staged)।
            git diff HEAD ==== সবকিছুই দেখায় (Staged + Unstaged)। অর্থাৎ লাস্ট কমিটের পর থেকে আপনি যত যা করেছেন।

User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (sakif_shahrear)
            $ git diff head
            diff --git a/L 4/Intern/one.txt b/L 4/Intern/one.txt
            index 3b0980f..f9f6be8 100644
            --- a/L 4/Intern/one.txt
            +++ b/L 4/Intern/one.txt
            @@ -11,7 +11,8 @@ int32_t main()
            for (int i = 0; i < n; i++)
            {
            int x, count=0;
            
            -        int y;
            
            *        int y,m,n,o;
            *        int change;
                       cin >> x;
            
                       for (int j = 1; j * j <= x; j++)
            
              diff --git a/L 4/Intern/phrase.md b/L 4/Intern/phrase.md
              index d7d5810..2a21fe3 100644
              --- a/L 4/Intern/phrase.md
              +++ b/L 4/Intern/phrase.md
              @@ -244,15 +244,51 @@ core.fscache=true
              core.symlinks=false
              pull.rebase=false
              credential.helper=manager
              -:
              +: ->> ** means there someting under which can't be shown here. for open terminal and type the command
              only q word. **
            
            3.  Global config থেকে একটি value remove করা
            
            email remove :
            
            git config --global --unset user.email
            
            -4️. পুরো user section delete করা
            +# পুরো user section delete করা
            
            git config --global --remove-section user
            
            -5️.
            \ No newline at end of file
            +4. Make a small file change, stage it, view staged changes only.
            
            - +staged command: git diff --staged (first git add korte hobe)
              +staged -> (state) which changes are added to the staging(state) area (git add) but not yet committed. (change ta git add kora hoyeche but git commit kora hoyni.)
              +আপনি যা নতুন যোগ করেছেন তা সবুজ রঙে (+) দেখাবে।
            - +যা মুছে ফেলেছেন তা লাল রঙে (-) দেখাবে।
            - +এটি শুধুমাত্র সেই পরিবর্তনগুলোই দেখাবে যেগুলো আপনি git add করেছেন কিন্তু এখনো commit করেননি।
            - +5. View all changes (staged + unstaged) compared to last commit.
            -
            - #include <bits/stdc++.h>
            - using namespace std;
            - +#define int long long
            -
            - -int main()
            - +int32_t main()
            - {
            -        int n;
            -        int x, y, z;
            - @@ -9,10 +10,10 @@ int main()
            - @@ -9,10 +10,10 @@ int main()
            -
            -        for (int i = 0; i < n; i++)
            -        {
            - -        int x;
            - -        int x, count=0;
            - -        int y;
            -            cin >> x;
            -
            - -        int count = 0;
            -            for (int j = 1; j * j <= x; j++)
            -            {
            -                if (x % j == 0)
            - (END)
            - # @@ -0,0 +1,36 @@: এর মানে ফাইলটি আগে খালি ছিল, এখন আপনি নতুন ১ থেকে ৩৬ নম্বর লাইন পর্যন্ত কোড যোগ গছেন।
              \ No newline at end of file
              (END)
Create a new file, add content, commit it with a clear message.
            echo "This is a new file" > newfile.txt
                git add newfile.txt
                git commit -m "Add newfile.txt with initial content"
                or
                touch newfile.txt
                echo "This is a new file" >> newfile.txt (use >> to append otherwise it will overwrite mane dekhane na)
                git add newfile.txt
                git commit -m "Add newfile.txt with initial content"
Rename a tracked file using Git (should stage automatically).
                git mv oldname.txt newname.txt
                    git commit -m "Rename oldname.txt to newname.txt"
                
                    proved :
                    $ git mv divisor.cpp change_divisor.cpp

Unstage a staged file without losing changes.
             cpmmand = git restore --staged <file_name>
Discard unstaged changes in a file.
                শুধু git restore <file> (কোড মুছে ফেলা - সাবধান!)
                    যদি আপনি --staged কথাটি না লিখেন, তবে এর কাজ হবে একদম আলাদা। ধরুন, আপনি ফাইলে অনেক কিছু লিখেছেন কিন্তু সব ভুল হয়েছে। আপনি চাচ্ছেন ফাইলটিকে একদম সেই অবস্থায় ফিরিয়ে নিতে যেমনটা লাস্ট কমিটের সময় ছিল।
                
                    তখন আপনি দিবেন: git restore one.txt
                
                    ফলাফল: আপনার শেষ কমিটের পর থেকে ফাইলে যা যা নতুন লিখেছেন, সব মুছে যাবে এবং ফাইলটি আগের অবস্থায় ফিরে যাবে। (এটি খুব সাবধানে ব্যবহার করতে হয়)।
View commit history in compact one-line format.
            git log --oneline
                proved:
                git log --oneline
                4613cd4 (HEAD -> sakif_shahrear, origin/sakif_shahrear) changed name
                bc4d863 divisor number
                d24a9a0 added some veriable in one.txt
                3295d8f added C++ basic structure in one.txt
                d812b20 start
View one-line history for a specific branch only.
              git log --oneline sakif_shahrear
              proved:
              4613cd4 (HEAD -> sakif_shahrear, origin/sakif_shahrear) changed name
              bc4d863 divisor number
              d24a9a0 added some veriable in one.txt
              3295d8f added C++ basic structure in one.txt
              d812b20 start
          
                  git log --oneline --graph --all
          
              proved:
              _ 5dec0ed (origin/adnan) Update Phase05.md
              _ 36f543a Add image for branch reset instructions
              _ be038c3 Add images and content for Phase 04 instructions
              _ 8d74b7a Update Phase04.md
              _ 37bb6c6 Update Phase04.md
              _ 3084ec0 Add images for amending the last commit
              _ d3d596b Update Phase04.md
              _ 9a052e1 Update Phase04.md
              _ 6f7d654 Update Phase05.md
              _ 863df0b Fix typo in Final Challenge section header
              _ c285a77 Document team flow simulation and capstone challenge
              _ 7729c1a Update Phase04.md

