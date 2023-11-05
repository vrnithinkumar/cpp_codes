#include <windows.h>
#include <iostream>

int print_dir_tree_rec(char* path, int* line) {
  WIN32_FIND_DATA findFileData;
  HANDLE findHandle = INVALID_HANDLE_VALUE;

  findHandle = FindFirstFile(path, &findFileData);

  if (findHandle == INVALID_HANDLE_VALUE) {
    std::cout << "FindFirstFile failed.\n";
    return -1;
  } 

  do {
    (*line)++;
    std::cout << "Line " << line << ": " << findFileData.cFileName << std::endl;
    if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      // if its a directory recursively call to print files
      print_dir_tree(findFileData.cFileName, line);
    }
  } while (FindNextFile(findHandle, &findFileData) != 0);

  FindClose(findFileData);
  return *line;
}

int print_dir_tree(char* path) {
  int line = 0;
  print_dir_tree_rec(path, &line);
  return line;
}
