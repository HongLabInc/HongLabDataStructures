import os
import shutil
import chardet


def get_immediate_subdirectories(dir_path):
    return [name for name in os.listdir(dir_path)
            if os.path.isdir(os.path.join(dir_path, name)) and name.startswith(("Ex", "shared"))]

def find_cpp_h_files(dir_path):
    cpp_h_files = []
    for root, dirs, files in os.walk(dir_path):
        for file in files:
            if file.endswith(('.cpp', '.h')):
                cpp_h_files.append(os.path.join(root, file))
    return cpp_h_files

def is_utf8_with_bom(file_path):
    with open(file_path, "rb") as f:
        encoding = chardet.detect(f.read())
        print(encoding)
    return encoding["encoding"].lower() == "utf-8-sig"

subdirs = get_immediate_subdirectories('.')
print(subdirs)

for sub in subdirs:

    print("VSCode/" + sub)

    if not os.path.isdir("VSCode/" + sub):
        os.makedirs("VSCode/" + sub)

    files = find_cpp_h_files(sub)
    for f in files:
        print(f + " to VSCode/" + f)
        # shutil.copy(f, "VSCode/" + f)

        if is_utf8_with_bom(f):
            shutil.copy(f, "VSCode/" + f)
        else:
            with open(f, 'r', encoding='cp949') as file:
                content = file.read()

            # 원본 파일도 인코딩 다시
            with open(f, 'w', encoding='utf-8-sig') as file:
                file.write(content)

            with open("VSCode/" + f, 'w', encoding='utf-8-sig') as file:
                file.write(content)



