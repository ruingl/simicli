from database import Database
from bprint import log
import time
import sys
import os

db = Database()

def clear() -> None:
    if os.name == "posix":
        os.system("clear")
    else:
        os.system("cls")

def main() -> None:
    clear()

    log("SimSimi")
    print("")

    print("Welcome!, What would you like?")
    print("")

    print("1. Teach Simi")
    print("2. Ask Simi")
    print("3. Exit")
    print("")

    user_input: str = input("$: ")
    if user_input == "1":
        teach()
    elif user_input == "2":
        ask()
    elif user_input == "3":
        print("Goodbye!")
        sys.exit(0)
    else:
        print("Invalid action.")
        time.sleep(0.5)
        main()

def teach() -> None:
    clear()

    log("Teach")
    print("")

    query: str = input("Query: ")
    response: str = input("Response: ")
    print("")

    db.add_response(query, response)
    print("Simi teached successfully!")
    print("")

    print("Would you like to go back? (y/n)")
    user_input: str = input("$: ")
    if user_input.lower() == "y":
        main()
    elif user_input.lower() == "n":
        print("Goodbye!")
        sys.exit(0)
    else:
        print("Invalid action.")
        time.sleep(0.5)
        main()

def ask() -> None:
    clear()

    log("Ask")
    print("")

    query: str = input("User: ")
    response: str = db.get_response(query)
    print("")

    print(f"Simi: {response}")
    print("")

    print("Would you like to continue? (y/n)")
    user_input: str = input("$: ")
    if user_input.lower() == "y":
        ask()
    elif user_input.lower() == "n":
        main()
    else:
        print("Invalid action.")
        time.sleep(0.5)
        main()

if __name__ == "__main__":
    main()
