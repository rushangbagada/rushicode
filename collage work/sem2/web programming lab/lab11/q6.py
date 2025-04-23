def update_membership(current_file, ex_file):
    with open(current_file, 'r') as current, open(ex_file, 'a') as ex:
        lines = current.readlines()
        header = lines[0]
        active_members = [header]
        removed_members = []

        for line in lines[1:]:
            if 'no' in line.split(',')[-1].strip().lower():
                removed_members.append(line)
            else:
                active_members.append(line)

   
    with open(current_file, 'w') as current:
        current.writelines(active_members)

   
    with open(ex_file, 'a') as ex:
        ex.writelines(removed_members)


update_membership("d:\\padhai\\rushicode\\collage work\\sem2\\web programming lab\\lab11\\currentMember.txt", "d:\\padhai\\rushicode\\collage work\\sem2\\web programming lab\\lab11\\exMember.txt")
print("Membership files have been updated.")