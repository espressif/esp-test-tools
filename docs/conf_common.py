from esp_docs.conf_docs import *  # noqa: F403,F401

languages = ['en', 'zh_CN']
idf_targets = ['esp32', 'esp32s2', 'esp32s3', 'esp32c3', 'esp32h2', 'esp32c2', 'esp32c6']

ESP32H2_DOCS = ['rf_test_items/esp32h2_ble_dtm_test.rst']

ESP32S3_DOCS = ['rf_test_items/esp32s3_c3_ble_dtm_test.rst']

conditional_include_dict = {'esp32h2':ESP32H2_DOCS,
                            'esp32s3':ESP32S3_DOCS}

extensions += ['sphinx_copybutton',
               'sphinxcontrib.wavedrom',
               'linuxdoc.rstFlatTable',
               'esp_docs.esp_extensions.dummy_build_system',
               ]

# link roles config
github_repo = 'espressif/esp-test-tools'

# context used by sphinx_idf_theme
html_context['github_user'] = 'espressif'
html_context['github_repo'] = 'esp-test-tools'

html_static_path = ['../_static']

#html_js_files = ['js/docs_version.js',
#                 'js/document_referrer.js']

# Extra options required by sphinx_idf_theme
project_slug = 'esp-test-tools'

# Contains info used for constructing target and version selector
# Can also be hosted externally, see esp-idf for example
versions_url = './_static/js/docs_version.js'

# Final PDF filename will contains target and version
pdf_file_prefix = u'esp-test-tools'

# Add Tracking id for Google Analytics
google_analytics_id = 'UA-132861133-1'

project_homepage = 'https://github.com/espressif/esp-test-tools'
