import math
import string

def arciausias(atstumai, startinis):
    tasku_skaicius = len(atstumai)
    aplankyti_taskai = [False] * tasku_skaicius
    kelias = []
    is_viso_atstumas = 0
    
    # pradeti pirmame taske
    dabartinis_taskas = startinis
    kelias.append(dabartinis_taskas)
    aplankyti_taskai[dabartinis_taskas] = True
    
    
    # kartoti kol apkeliaujiami visi taskai
    while len(kelias) < tasku_skaicius:
        arciausias_taskas = None
        arciausias_atstumas = math.inf

        # surasti artimiausia neaplankyta taska
        for taskas in range(tasku_skaicius):
            if not aplankyti_taskai[taskas]:
                atstumas = atstumai[dabartinis_taskas][taskas]
                if atstumas < arciausias_atstumas:
                    arciausias_taskas = taskas
                    arciausias_atstumas = atstumas

        # pereiti i arciausia taska
        dabartinis_taskas = arciausias_taskas
        kelias.append(dabartinis_taskas)
        aplankyti_taskai[dabartinis_taskas] = True
        is_viso_atstumas += arciausias_atstumas

    # Pabaigti visa marsruta griztant i pradini taska
    kelias.append(startinis)
    is_viso_atstumas += atstumai[dabartinis_taskas][0]

    return kelias, is_viso_atstumas

atstumai = []
kelias = []
is_viso_atstumas = []
with open("duomenys.txt", "r") as new_file:
    file = new_file.read()
    parts = file.split("\n")
    for part in parts:
        temp = part.split(" ")
        for item in range(len(temp)):
            temp[item] = int(temp[item])
        atstumai.append(temp)
    new_file.close()

for i in range(len(atstumai)):
    temp1, temp2 = arciausias(atstumai, i)
    kelias.append(temp1)
    is_viso_atstumas.append(temp2)
abecele = list(string.ascii_lowercase)
for i in range(len(atstumai)):
    for item in range(len(kelias[i])):
        kelias[i][item] = abecele[kelias[i][item]]
min_index = min(is_viso_atstumas)
min_index = is_viso_atstumas.index(min_index)

with open("rezultatai.txt", "w") as new_file:
    for i in range(len(atstumai)):
        new_file.write(f"Kelias: {kelias[i]}\n")
        new_file.write(f"Visas kelias: {is_viso_atstumas[i]}\n")
    new_file.write(f"Trumpiausias kelias: {kelias[min_index]}\n")
    new_file.write(f"Visas kelias: {is_viso_atstumas[min_index]}\n")
    new_file.close()


print("Kelias:", kelias)
print("Nueito kelio suma:", is_viso_atstumas)