import json
import sys

class Database:
    def __init__(self) -> None:
        self.db: dict[str, str] = {}
        self.seed: dict[str, str] = {}

        try:
            with open("database.json", "r") as file:
                self.db = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            with open("database.json", "w") as file:
                json.dump(self.seed, file)
            self.db = self.seed
        except Exception as e:
            print(f"[-] Cant init database. {e}")
            sys.exit(1)

    def get_response(self, query: str) -> str:
        query_formatted = query.lower().replace(" ", "")
        if query_formatted in self.db:
            return self.db[query_formatted]
        else:
            return "I dont know that yet!"

    def add_response(self, query: str, response: str) -> None:
        query_formatted = query.lower().replace(" ", "")
        if query_formatted in self.db:
            return # Do Nothing
        else:
            self.db[query_formatted] = response

            try:
                with open("database.json", "w") as file:
                    json.dump(self.db, file)
            except Exception as e:
                print(f"[-] Cant save response! {e}")
