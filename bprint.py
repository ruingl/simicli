import time

def log(text: str) -> None:
    text_length: int = len(text)
    border_length: int = text_length + 4

    for i in range(border_length):
        print("*", end="", flush=True)
        time.sleep(0.099)
    print("")

    print("* ", end="")
    for i in range(text_length):
        print(text[i], end="", flush=True)
        time.sleep(0.099)
    print(" *")

    for i in range(border_length):
        print("*", end="", flush=True)
        time.sleep(0.099)
    print("")
