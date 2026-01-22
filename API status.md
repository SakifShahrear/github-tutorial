1xx — Informational (Processing Stage)

👉 Server বলছে:

“Request পাইছি, কাজ শুরু করছি”

✅ 100 Continue

📌 Client বড় data পাঠানোর আগে permission চায়

Example:

File upload শুরু করার আগে server বলছে continue করো

✅ 101 Switching Protocols

📌 HTTP → WebSocket switch

Example:

Live chat app

Real-time notification

✅ 102 Processing

📌 Request heavy, time লাগবে

Example:

Big report generation

🔥 Real API তে খুব কম use হয়

🟢 2xx — Success Codes (সব ঠিকঠাক)

👉 Server বলছে:

“কাজ শেষ, সফল” 🎉

✅ 200 OK

সবচেয়ে common status

Example:

User list load

Product fetch

Laravel example:

return response()->json($data, 200);

✅ 201 Created

নতুন resource তৈরি হয়েছে

Example:

Register user

Create order

return response()->json($user, 201);

✅ 202 Accepted

Request গ্রহণ করা হয়েছে
Processing চলবে background এ

Example:

Email sending queue

Payment verification

✅ 204 No Content

Success কিন্তু কিছু return নাই

Example:

Delete success

return response()->noContent();

🟡 3xx — Redirect (Resource moved)

👉 Server বলছে:

“এই URL না, ওখানে যাও”

✅ 301 Permanent Redirect

Permanent URL change

SEO important

Example:

/api/v1/users  
➡ /api/v2/users  

✅ 302 Temporary Redirect

Temporary change

Maintenance সময় use হয়

✅ 304 Not Modified

Cache ব্যবহার করো

Example:

Browser same image reload করে না

🔥 Speed optimization

✅ 307 / 308

Modern redirect
POST method safe রাখে

🟠 4xx — Client Side Error (তোমার ভুল 😅)

👉 Server বলছে:

“Request ঠিক না”

❌ 400 Bad Request

Wrong input

Example:

Email format ভুল

Missing field

❌ 401 Unauthorized

Login নাই

Example:

Token missing

❌ 403 Forbidden

Permission নাই

Example:

Admin route user access করছে

❌ 404 Not Found

Route/API নাই

Example:

URL typo

❌ 405 Method Not Allowed

GET দিয়ে POST API call

❌ 422 Validation Error 🔥

Laravel এ সবচেয়ে common

Example:

Password < 8 char

{
 "error": "Validation failed"
}

❌ 429 Too Many Requests

Rate limit exceeded

Example:

1 minute এ 100+ request

🔴 5xx — Server Error (Backend problem 😵)

👉 Server বলছে:

“আমার ভিতরের সমস্যা”

💥 500 Internal Server Error

Code crash

Example:

Null error

DB fail

💥 502 Bad Gateway

API → API communication fail

Example:

Microservice down

💥 503 Service Unavailable

Server busy

Example:

Maintenance

💥 504 Gateway Timeout

Response দেরি

🎯 Laravel Best Practice Status Use
Operation	Code
Fetch	200
Create	201
Delete	204
Validation Error	422
Auth Error	401
Server Crash	500
