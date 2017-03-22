from nose.tools import *
from bin.app import app
from tests.tools import assert_response

def test_index():
    resp=app.request("/")
    assert_response(resp,status="404")
