import os
import shutil
from pathlib import Path

import pandas as pd
import requests
import urllib3

import re

def sanitize(text):
    return re.sub(r'[<>:"/\\|?*]', '_', str(text))

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

df = pd.read_csv("Digikey_Datasheet_List.csv")

#print(df)

docs_dir = Path("../datasheet")

if docs_dir.exists():
    pass
    # shutil.rmtree(docs_dir)

else:
    docs_dir.mkdir()

urls = df["Fiche technique"]
fabs = df["Nom du fabricant"]
descs = df["Description"]

if len(urls) == len(fabs) == len(descs):
    pass
else:
    print("lenght error")
    exit()

for i in range(len(urls)):
    if pd.isna(urls[i]):
        raise ValueError(
            f"Ligne {i}: URL manquante pour {fabs[i]} - {descs[i]}"
        )

errors = []

for i in range(0, len(urls)):
    try:
        #print(f"Téléchargement : {fabs[i]} \t {descs[i]} \t {urls[i]}")
        print(f"Téléchargement : {i/len(urls)*100:.1f}%", end="   \r")
        filename = docs_dir / f"{sanitize(fabs[i])[:50]}-{sanitize(descs[i])[:100]}.pdf"

        f = Path(filename)

        if f.exists():
            continue

        response = requests.get(urls[i], timeout=5, verify=False)
        response.raise_for_status()

        content_type = response.headers.get("content-type", "")

        if "pdf" not in content_type.lower():
            errors.append(f"not a pdf : {filename} \t {urls[i]}")

        with open(filename, "wb") as f:
            f.write(response.content)

    except Exception as e:
        errors.append(f"error {e} : {filename} \t {urls[i]}")

for err in errors:
    print()
    print("-"*50)
    print(err)