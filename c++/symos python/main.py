def pertvarkyti_teksta(tekstas):
    zodziai = tekstas.split()
    sujungti_zodziai = []

    for zodis in zodziai:
        if zodis.endswith('-') and zodis[:-1]:
            sujungti_zodziai[-1] += zodis.rstrip('-')
        else:
            sujungti_zodziai.append(zodis)

    return " ".join(sujungti_zodziai)

def main():
    try:
        with open("ivykdytas_failas.txt", "r", encoding="utf-8") as skaitymo_failas:
            tekstas = skaitymo_failas.read()

        pertvarkytas_tekstas = pertvarkyti_teksta(tekstas)

        with open("pertvarkytas_failas.txt", "w", encoding="utf-8") as rasymo_failas:
            rasymo_failas.write(pertvarkytas_tekstas)

        print("Tekstas sėkmingai pertvarkytas ir išsaugotas į failą.")
    except FileNotFoundError:
        print("Klaida: Failas nerastas.")
    except Exception as e:
        print(f"Klaida: {e}")

if __name__ == "__main__":
    main()