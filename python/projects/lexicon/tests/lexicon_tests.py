from nose.tools import *
from lexicon.lexicon import lexicon
#import lexicon


def test_directions():
    assert_equal(lexicon.scan("north"),[('direction','north')])
    assert_equal(lexicon.scan("east"),[('direction','east')])
