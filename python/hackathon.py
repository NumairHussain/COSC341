from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.backends import default_backend

key = b"Boy, don't call me angel"
iv = b"11152019"
ciphertext = bytes.fromhex("5b3b538d6dab0a22806e7581032987ddab54a115521b9f4f1d94c699d2b54ba0")

backend = default_backend()
cipher = Cipher(algorithms.TripleDES(key), modes.CBC(iv), backend=backend)
decryptor = cipher.decryptor()
decrypted = decryptor.update(ciphertext) + decryptor.finalize()

unpadder = padding.PKCS7(64).unpadder()
plaintext = unpadder.update(decrypted) + unpadder.finalize()

print(plaintext.decode('utf-8'))