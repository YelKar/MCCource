namespace utils {
    int map(int);
}

int utils::map(int x) {
    return ::map(x, -100, 100, -255, 255);
}
