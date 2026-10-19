# Mini Bank Application

A console-based banking application written in **C**. Customers can open, update, view, list and close accounts, and transfer money between accounts in different currencies. All data is saved to a file, so it is kept between runs.

Developed as a first-year programming course project (CMPE1101).

## Features

- **Create account:** Name, surname, TC ID, 8-digit account number, starting balance and currency (TRY / USD / EUR).
- **Update account:** Change the details of an existing account.
- **Close account:** Removes the account and shifts the remaining records in the array.
- **Account inquiry:** Shows the details of a single account.
- **Account listing:** Lists every customer in the bank.
- **Money transfer with currency conversion:** Transfers between TRY, USD and EUR accounts using fixed exchange rates. The amount cannot be more than the sender's balance.
- **Receipts:** Optionally writes a receipt to a text file when an account is opened, closed or a transfer is made.
- **Persistent storage:** Customer data is saved to `customers.txt` after every operation and loaded automatically when the program starts.

## Technical Details

- Customer records are stored in a `struct customers_info` array (up to 5000 customers).
- Each operation is implemented as a separate function (`new_customer`, `update_account`, `account_closure`, `account_inquiry`, `account_listing`, `transfer_money`).
- File I/O with `fopen`, `fprintf` and `fscanf` (`save_customers` / `load_customers`).

### Exchange rates used

| From \ To | TRY | USD | EUR |
|---|---|---|---|
| **TRY** | 1 | ÷ 35.16 | ÷ 36.63 |
| **USD** | × 35.16 | 1 | ÷ 1.04 |
| **EUR** | × 36.63 | × 1.04 | 1 |

Rates are fixed in the code and were chosen at the time the project was written.

## Build & Run

Requires a C compiler (e.g. GCC).

```bash
gcc -o mini_bank mini_bank.c
./mini_bank
```

On Windows (MinGW):

```bash
gcc -o mini_bank.exe mini_bank.c
mini_bank.exe
```

## Menu

```
1. Create New Customer Account
2. Account Update
3. Account Closure
4. Account Inquiry
5. Account Listing
6. Money Transfer
0. Exit
```

## Files Created at Runtime

| File | Content |
|---|---|
| `customers.txt` | All customer records |
| `account_receipt.txt` | Receipts for newly opened accounts |
| `account_closing_receipt.txt` | Receipts for closed accounts |
| `transfer_money.txt` | Receipts for money transfers |

## Example

```
Transferred money:10.000 USD from Ayse Kaya to Ali Yilmaz||Remaining amount:90.000 USD
```

Ali's TRY account receives 10 × 35.16 = 351.60 TRY.

## Limitations

- Names and surnames are read as single words (no spaces).
- Exchange rates are hard-coded.
