def file_sort(infile, outfile):
    infile = open(infile, 'r')
    num_students = int(infile.read)

    student_id = []
    name = []
    gpa = []

    for i in range(num_students):
        line = infile.readline().strip()
        stu_id, stu_name, stu_gpa = line.split()
        student_id.insert(len(student_id), int(stu_id))
        name.insert(len(name), str(stu_name))
        gpa.insert(len(gpa), stu_gpa)

    infile.close()

    for i in range(num_students):
        for j in range(i + 1, num_students):
            if student_id[i] < student_id[j]:
                student_id[i], student_id[j] = student_id[j], student_id[i]
                name[i], name[j] = name[j], name[i]
                gpa[i], gpa[j] = gpa[j], gpa[i]

    outfile = open(outfile, 'w')
    outfile.write(str(num_students) + '\n')
    for i in range(num_students):
        outfile.write(student_id[i] + " " + name[i] + " " + gpa[i] + "\n")

    


