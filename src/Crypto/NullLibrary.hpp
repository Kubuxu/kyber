#ifndef DISSENT_CRYPTO_NULL_LIBRARY_H_GUARD
#define DISSENT_CRYPTO_NULL_LIBRARY_H_GUARD

#include "NullHash.hpp"
#include "../Utils/Random.hpp"
#include "NullPrivateKey.hpp"
#include "NullPublicKey.hpp"

#include "Library.hpp"

namespace Dissent {
namespace Crypto {
  class NullLibrary : public Library {
    public:
      /**
       * Load a public key from a file
       */
      inline virtual AsymmetricKey *LoadPublicKeyFromFile(const QString &filename)
      {
        return new NullPublicKey(filename);
      }

      /**
       * Loading a public key from a byte array
       */
      inline virtual AsymmetricKey *LoadPublicKeyFromByteArray(const QByteArray &data) 
      {
        return new NullPublicKey(data);
      }

      /**
       * Generate a public key using the given data as a seed to a RNG
       */
      inline virtual AsymmetricKey *GeneratePublicKey(const QByteArray &seed)
      {
        return NullPublicKey::GenerateKey(seed);
      }

      /**
       * Load a private key from a file
       */
      inline virtual AsymmetricKey *LoadPrivateKeyFromFile(const QString &filename) 
      {
        return new NullPrivateKey(filename);
      }

      /**
       * Loading a private key from a byte array
       */
      inline virtual AsymmetricKey *LoadPrivateKeyFromByteArray(const QByteArray &data) 
      {
        return new NullPrivateKey(data);
      }

      /**
       * Generate a private key using the given data as a seed to a RNG
       */
      inline virtual AsymmetricKey *GeneratePrivateKey(const QByteArray &seed) 
      {
        return NullPrivateKey::GenerateKey(seed);
      }

      /**
       * Generates a unique (new) private key
       */
      inline virtual AsymmetricKey *CreatePrivateKey() 
      {
        return new NullPrivateKey();
      }

      /**
       * Returns a random number generator
       */
      inline virtual Dissent::Utils::Random *GetRandomNumberGenerator() 
      {
        return new Dissent::Utils::Random();
      }

      /**
       * Returns a hash algorithm
       */
      inline virtual Hash *GetHashAlgorithm() 
      {
        return new NullHash();
      }
  };
}
}

#endif
