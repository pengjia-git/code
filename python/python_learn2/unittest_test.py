#coding=utf-8
import unittest
import sys
sys.path.append("/Users/jia/code/python/python_learn2")

from email_test import is_email_valid

class MyTest(unittest.TestCase):  # 继承unittest.TestCase
    def tearDown(self):
        pass

    def setUp(self):
        pass

    @classmethod
    def tearDownClass(self):
    # 必须使用 @ classmethod装饰器, 所有test运行完后运行一次
        pass
    @classmethod
    def setUpClass(self):
    # 必须使用@classmethod 装饰器,所有test运行前运行一次
        pass

    def test_a_run(self):
        self.assertTrue(True,is_email_valid("1730548875@qq.com"))  # 测试用例
        
    def test_b_run(self):
        self.assertEqual(False,is_email_valid(""))  # 测试用例
        
if __name__ == '__main__':
    unittest.main()#运行所有的测试用例