#ifndef PROTO_PATH_H
#define PROTO_PATH_H

char *proto_path_basename(const char *path);
char *proto_path_join(const char *dir, const char *file);
int proto_path_is_absolute(const char *path);

#endif /* PROTO_PATH_H */
