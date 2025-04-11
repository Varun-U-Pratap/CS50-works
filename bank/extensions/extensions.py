inp = input("File name: ").strip().lower().split(".")
if inp[-1] == "gif":
    print("image/gif",end="")
elif inp[-1] in ("jpeg", "jpg"):
    print("image/jpeg", end="")
elif inp[-1] == "png":
    print("image/png", end="")
elif inp[-1] == "pdf":
    print("application/pdf", end="")
elif inp[-1] == "txt":
    print("text/plain", end="")
elif inp[-1] == "zip":
    print("application/zip", end="")
else:
    print("application/octet-stream", end='')
