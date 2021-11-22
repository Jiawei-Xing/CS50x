-- Keep a log of any SQL queries you execute as you solve the mystery.

-- enter the database
sqlite3 fiftyville.db

-- show what's inside the database
.table
.schema

-- search crime scene reports with date and street
SELECT description FROM crime_scene_reports WHERE year = '2020' AND month = '7' AND day = '28' AND street = 'Chamberlin Street';

-- search interviews with date and keyword "courthouse"
SELECT transcript FROM interviews WHERE year = '2020' AND month = '7' AND day = '28' AND transcript LIKE "%courthouse%";

-- search courthouse security logs with time and "exit"
SELECT license_plate FROM courthouse_security_logs WHERE year = '2020' AND month = '7' AND day = '28' AND hour = '10' AND minute > '15' AND minute < '25' AND activity = 'exit';

-- search ATM transactions with date, street, and "withdraw"
SELECT account_number FROM atm_transactions WHERE year = '2020' AND month = '7' AND day = '28' AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw';

-- search phone calls with date and duration < 1 min
SELECT caller, receiver FROM phone_calls WHERE year = '2020' AND month = '7' AND day = '28' AND duration < '60';

-- search flights with origin airport and time
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = '2020' AND month = '7' AND day = '29' ORDER BY hour, minute LIMIT 1);

-- search passengers with flight id
SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = '2020' AND month = '7' AND day = '29' ORDER BY hour, minute LIMIT 1);

-- search for the thief with license, account number, caller number, and passport
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = '2020' AND month = '7' AND day = '28' AND duration < '60') AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = '2020' AND month = '7' AND day = '28' AND hour = '10' AND minute > '15' AND minute < '25' AND activity = 'exit') AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = '2020' AND month = '7' AND day = '29' ORDER BY hour, minute LIMIT 1)) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = '2020' AND month = '7' AND day = '28' AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw'));

-- search for the accomplice with receiver number given the known caller number
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = '2020' AND month = '7' AND day = '28' AND duration < '60' AND caller = (SELECT phone_number FROM people WHERE name = (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = '2020' AND month = '7' AND day = '28' AND duration < '60') AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = '2020' AND month = '7' AND day = '28' AND hour = '10' AND minute > '15' AND minute < '25' AND activity = 'exit') AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = '2020' AND month = '7' AND day = '29' ORDER BY hour, minute LIMIT 1)) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = '2020' AND month = '7' AND day = '28' AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw')))));
