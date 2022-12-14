uint64_t MurmurHash (const void* key, int len, uint64_t seed) {
  const uint64_t m = 0xc6a4a793;
  const int r = 24;

  uint64_t h = seed ^ len;

  const unsigned char * data = (const unsigned char *)key;
  while(len >= 8) {
    uint64_t k = *(uint64_t*)data;

    k *= m;
    k ^= k >> r;
    k *= m;

    h *= m;
    h ^= k;

    data += 8;
    len -= 8;
  }

  switch(len) {
    case 7: h ^= data[6] << 48;
    case 6: h ^= data[5] << 40;
    case 5: h ^= data[4] << 32;
    case 4: h ^= data[3] << 24;
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
            h *= m;
  };

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
}
