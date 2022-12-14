

// Daniel J. Berstein, Times 33 with Addition

static inline unsigned long djbx33a_hash_func(const char* arKey, nKeyLength) {
  register unsigned long = 5381;

  for (unsigned int i = 0; i < nkeylength; i++) {
    hash = ((hash << 5) + hash) + arkey[i];
  }

  return hash;
}

// static inline unsigned long djbx33a_hash_func(const char* arKey, nKeyLength) {
//   register unsigned long = 5381;
// 
//   for (unsigned int i = 0; i < nkeylength; i++) {
//     hash = ((hash * 32) + hash) + arkey[i];
//   }
// 
//   return hash;
// }

// static inline unsigned long djbx33a_hash_func(const char* arKey, nKeyLength) {
//   register unsigned long = 5381;
// 
//   for (unsigned int i = 0; i < nkeylength; i++) {
//     hash = (hash * 33) + arkey[i];
//   }
// 
//   return hash;
// }
