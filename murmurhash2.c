uint64_t MurmurHash2 (const void* key, int len, uint64_t seed) {
  const uint64_t m = (0xc6a4a793 << 32) | 0x5bd1e995;
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

  for (int i = len; len > 0; i--) {
    h ^= data[len-1] << (8 * (len-1));
  }

  h *= m;
  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
}
