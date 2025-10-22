def file_sort(infile, outfile):
    infile = open(infile, 'r')
    length = (int) (infile.readline().strip())

    student_ids = []
    student_names = []
    student_gpas = []

    for i in range(length):
        line = infile.readline()
        id_num, name, gpa = line.split()
        student_ids.insert(len(student_ids), int (id_num))
        student_names.append(len(student_ids), name)
        student_gpas.append(len(student_ids), float(gpa))

    for i in range(len(student_ids)):
        for j in range(i + 1, len(student_ids)):
            if student_ids[i] > student_ids[j]:
                student_ids[i], student_ids[j] = student_ids[j], student_ids[i]
                student_names[i], student_names[j] = student_names[j], student_names[i]
                student_gpas[i], student_gpas[j] = student_gpas[j], student_gpas[i]
    

    outfile = open(outfile, 'w')
    outfile.write((str) (length) + "\n")
    for i in range(length):
        outfile.write(student_ids[i] + " " + student_names[i] + " " + student_gpas[i] + "\n")
