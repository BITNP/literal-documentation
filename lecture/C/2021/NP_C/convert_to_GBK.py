# https://docs.python.org/zh-cn/3.9/library/shutil.html#copytree-example

import os
from os.path import splitext, join

src_dirs = ('./file/', './link_list', './struct/')


def copy_and_convert_C_program(path, filename):
    main_name, ext_name = splitext(filename)
    assert ext_name == '.c', "Not a C program."

    with open(join(path, filename), "r", encoding='utf-8') as src_f:
        with open(join(path, main_name + "-gbk" + ext_name),
                  "w", encoding='gbk', errors='replace') as dst_f:
            dst_f.write(src_f.read())


def copy_and_convert_dir(dirname):
    for root, dirs, files in os.walk(dirname):
        for name in files:
            main_name, ext_name = splitext(name)
            if ext_name == '.c' and '-gbk' not in main_name:
                print(f'正在复制并转换 {join(root,name)}。')
                copy_and_convert_C_program(root, name)

        for name in dirs:
            copy_and_convert_dir(name)


for src_dir in src_dirs:
    copy_and_convert_dir(src_dir)
