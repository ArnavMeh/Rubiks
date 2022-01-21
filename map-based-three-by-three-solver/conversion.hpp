U8 toBitCorner(U8 id) {
    U8 orient = id >> 3;
    U8 position = id & 7;
    return (orient << 4) | position;
}
U8 toBitEdge(U8 id) {
    U8 orient = id / 12;
    U8 position = id % 12;
    return (orient << 4) | position;
}