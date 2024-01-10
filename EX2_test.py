import EX2
import unittest

class TestEX2(unittest.TestCase):
	def test_fifo(self):
		fifo = EX2.FIFO()
		fifo.push(1)
		fifo.push(2)
		fifo.push(3)
		self.assertEqual(fifo.pop(), 1)
		self.assertEqual(fifo.pop(), 2)
		self.assertEqual(fifo.pop(), 3)
		self.assertEqual(fifo.pop(), None)
		
	def test_lifo(self):
		lifo = EX2.LIFO()
		lifo.push(1)
		lifo.push(2)
		lifo.push(3)
		self.assertEqual(lifo.pop(), 3)
		self.assertEqual(lifo.pop(), 2)
		self.assertEqual(lifo.pop(), 1)
		self.assertEqual(lifo.pop(), None)
		
	def test_lilo(self):
		lilo = EX2.LILO()
		lilo.push(1)
		lilo.push(2)
		lilo.push(3)
		self.assertEqual(lilo.pop(), 1)
		self.assertEqual(lilo.pop(), 2)
		self.assertEqual(lilo.pop(), 3)
		self.assertEqual(lilo.pop(), None)
	
if __name__ == '__main__':
	unittest.main()