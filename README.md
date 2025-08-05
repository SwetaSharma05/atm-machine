# 💳 ATM Simulation Project (Java)

This is a simple console-based **ATM simulation system** implemented in Java. It mimics basic ATM operations such as:
- User authentication via PIN
- Checking account balance
- Depositing money
- Withdrawing money
- Viewing account details

---

## 🏗️ Project Structure

- `BankAccount.java`  
  Contains the `BankAccount` class with attributes like account holder name, account number, balance, and PIN. Includes methods to authenticate, deposit, withdraw, and display account info.

- `ATM.java`  
  Handles user interaction and simulates an ATM menu. It prompts the user for their PIN and allows them to perform transactions after successful authentication.

- `Main.java`  
  The main entry point of the program. It creates a sample `BankAccount` and starts the ATM session.

---

## 🚀 How to Run

### Prerequisites:
- Java JDK installed on your system (version 8 or later)
- A terminal or IDE (like IntelliJ IDEA or Eclipse)

### Steps:

1. **Save the files:**
   - Save the entire code in a single file called `Main.java`  
     _(or separate into `BankAccount.java`, `ATM.java`, and `Main.java` if preferred)_

2. **Compile the code:**
   ```bash
   javac Main.java
