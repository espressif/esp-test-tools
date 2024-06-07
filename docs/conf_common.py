from esp_docs.conf_docs import *  # noqa: F403,F401

languages = ['en', 'zh_CN']
idf_targets = ['esp32', 'esp32c2', 'esp32c3', 'esp32c6', 'esp32s2', 'esp32s3', 'esp32h2']

WIFI_DOCS = ['development_stage/rf_test_items/wifi_signaling_test.rst',
              'development_stage/rf_test_items/wifi_adaptivity_test.rst',
              'development_stage/rf_test_items/wifi_blocking_test.rst',
              'development_stage/rf_test_items/wfa_certification_test.rst',
              'development_stage/rf_test_items/wifi_non_signaling_test.rst',]

BLE_DOCS = ['development_stage/rf_test_items/ble_dtm_test.rst',
              'development_stage/rf_test_items/ble_adaptivity_test.rst',
              'development_stage/rf_test_items/ble_blocking_test.rst']

ZIGBEE_DOCS = ['development_stage/rf_test_items/zigbee_non_signaling_test.rst']

ESP32_DOCS = WIFI_DOCS
ESP32C2_DOCS = WIFI_DOCS + BLE_DOCS
ESP32C3_DOCS = WIFI_DOCS + BLE_DOCS
ESP32C6_DOCS = WIFI_DOCS + BLE_DOCS + ZIGBEE_DOCS
ESP32S2_DOCS = WIFI_DOCS
ESP32S3_DOCS = WIFI_DOCS + BLE_DOCS
ESP32H2_DOCS = BLE_DOCS + ZIGBEE_DOCS

conditional_include_dict = {'esp32':ESP32_DOCS,
                            'esp32c2':ESP32C2_DOCS,
                            'esp32c3':ESP32C3_DOCS,
                            'esp32c6':ESP32C6_DOCS,
                            'esp32s2':ESP32S2_DOCS,
                            'esp32s3':ESP32S3_DOCS,
                            'esp32h2':ESP32H2_DOCS}

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
