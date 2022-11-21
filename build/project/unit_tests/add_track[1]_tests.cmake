add_test([=[Test.Test]=]  /home/marcussss1/2022_2_MidnightSun/build/project/unit_tests/add_track [==[--gtest_filter=Test.Test]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Test.Test]=]  PROPERTIES WORKING_DIRECTORY /home/marcussss1/2022_2_MidnightSun/build/project/unit_tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  add_track_TESTS Test.Test)
