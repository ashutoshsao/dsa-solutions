import os

for filename in os.listdir("."):
    if not filename or not filename[0].isupper():
        continue  # Skip files that don't start with an uppercase letter

    new_name = filename[0].lower() + filename[1:]
    if new_name == filename:
        continue  # Skip if already lowercase

    # Use a temp name to avoid case-insensitive filesystem conflict
    temp_name = "__TMP__" + filename

    try:
        os.rename(filename, temp_name)  # Step 1: rename to temp
        os.rename(temp_name, new_name)  # Step 2: rename to lowercase
        print(f"Renamed: {filename} → {new_name}")
    except Exception as e:
        print(f"Error renaming {filename}: {e}")
