API Authentication মানে হলো 👉 কোনো API ব্যবহার করার আগে user বা application-এর পরিচয় যাচাই করা।
API Authentication দরকার হয় কারণ:

✔ Unauthorized access বন্ধ করতে
✔ ডাটা সিকিউর রাখতে
✔ কে কত request করছে সেটা কন্ট্রোল করতে
✔ Abuse / hacking আটকাতে

API Authentication কীভাবে কাজ করে?

1️⃣ API provider থেকে API Key নিলে
2️⃣ Request পাঠানোর সময় key যুক্ত করলে
3️⃣ Server key verify করলো
4️⃣ Valid হলে data পাঠালো
5️⃣ Invalid হলে error দিল ❌

Laravel দিয়ে API বানানো (Easy Example)
Step 1: Laravel Project Create
Terminal: composer create-project laravel/laravel api_project
Step 2: API Route বানাও
ফাইল খুল: routes/api.php

Add করো:
Route::get('/hello', function () {
    return response()->json([
        "status" => true,
        "message" => "Hello API"
    ]);
});


Step 3: Server Run করো
php artisan serve

Step 4: Browser / Postman এ test করো

Open:

http://127.0.0.1:8000/api/hello


Response আসবে:

{
  "status": true,
  "message": "Hello API"
}


🎉 তোমার প্রথম API তৈরি হয়ে গেছে!

✅ Database Connected API Example
Step 1: Migration + Model বানাও
php artisan make:model Student -m

Step 2: Migration file edit
$table->string('name');
$table->string('email');

Step 3: Migrate
php artisan migrate

Step 4: Controller বানাও
php artisan make:controller StudentController

Step 5: Controller Code
use App\Models\Student;

public function index()
{
    $students = Student::all();

    return response()->json($students);
}

Step 6: Route add করো

api.php:

Route::get('/students', [StudentController::class, 'index']);

Step 7: Test

URL:

http://127.0.0.1:8000/api/students


Database data JSON আকারে আসবে 👍

🔐 Authentication যুক্ত API (Real Project)

যেমন:

POST /api/login
GET /api/profile


Flow:

✔ Login → Token generate
✔ Token দিয়ে API call
✔ Server verify
✔ Data return

(এটা JWT / Sanctum দিয়ে হয়)
