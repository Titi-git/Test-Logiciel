import funcs
import unittest


class TestFuncs(unittest.TestCase):

    def max_3(self):
        self.assertEqual(funcs.max_3([1, 2, 3, 4, 5]), [5, 4, 3])
        self.assertEqual(funcs.max_3([1, 2, 3, 4, 5, 6, 7]), [7, 6, 5])
        self.assertEqual(funcs.max_3([1, 2, 3, 4, 5, 6, 7, 8, 9]), [9, 8, 7])
        self.assertEqual(funcs.max_3([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), [10, 9, 8])
        self.assertEqual(funcs.max_3([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]), [11, 10, 9])
        self.assertEqual(funcs.max_3([13, 24, 35, 46, 53, 26, 47, 58, 69, 10, 11, 12]), [69, 58, 53])

    def min_n(self):
        self.assertEqual(funcs.min_n([1, 2, 3, 4, 5], 2), [1, 2])
        self.assertEqual(funcs.min_n([6, 7, 3, 4, 5, 6, 7], 3), [3, 4, 5])
        self.assertEqual(funcs.min_n([5, 2, 3, 4, 5, 6, 7, 8, 9], 3), [2, 3, 4])

    def is_prime(self):
        self.assertEqual(funcs.is_prime(1), True)
        self.assertEqual(funcs.is_prime(2), False)
        self.assertEqual(funcs.is_prime(3), True)
        self.assertEqual(funcs.is_prime(4), False)

    def is_arithmetic(self):
        self.assertEqual(funcs.is_arithmetic([1, 2, 3, 4, 5]), True)
        self.assertEqual(funcs.is_arithmetic([1, 2, 3, 4, 5, 6, 7]), True)
        self.assertEqual(funcs.is_arithmetic([1, 2, 3, 4, 5, 6, 7, 8, 9]), True)
        self.assertEqual(funcs.is_arithmetic([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), True)
        self.assertEqual(funcs.is_arithmetic([1, 3, 5, 7, 9]), True)
        self.assertEqual(funcs.is_arithmetic([13, 24, 35, 46, 53, 26, 47, 58, 69, 10, 11, 12]), False)

    def is_geometric(self):
        self.assertEqual(funcs.is_geometric([1, 2, 3, 4, 5]), False)
        self.assertEqual(funcs.is_geometric([1, 2, 4, 8, 16, 32, 64]), True)
        self.assertEqual(funcs.is_geometric([1, 3, 5, 7, 9]), False)
        self.assertEqual(funcs.is_geometric([1,1,1,1,1,1,1,1]), True)

if __name__ == '__main__':
	unittest.main()