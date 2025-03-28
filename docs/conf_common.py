from esp_docs.conf_docs import *  # noqa: F403,F401

languages = ['en', 'zh_CN']
idf_targets = ['esp8266', 'esp32', 'esp32c2', 'esp32c3', 'esp32c6', 'esp32s2', 'esp32s3', 'esp32h2']

BLE_DOCS = ['development_stage/rf_test_items/ble_adaptivity_test.rst',
            'development_stage/rf_test_items/ble_blocking_test.rst',
            'development_stage/rf_test_items/ble_dtm_test.rst']

BT_DOCS = ['development_stage/rf_test_items/bt_ble_non_signaling_test.rst']

WIFI_DOCS = ['development_stage/rf_test_items/wifi_adaptivity_test.rst',
             'development_stage/rf_test_items/wifi_blocking_test.rst',
             'development_stage/rf_test_items/wifi_non_signaling_test.rst',
             'development_stage/rf_test_items/wifi_signaling_test.rst']

ZIGBEE_DOCS = ['development_stage/rf_test_items/zigbee_non_signaling_test.rst']

WFA_DOCS = ['development_stage/wfa_certification_test/wfa_certification_test.rst']

MATTER_DOCS = ['production_stage/tools/matter_qr_code_generator.rst']

PRODUCT_DOCS = ['production_stage/tools/esp_production_testing_guide.rst']

ESP8266_DOCS = WIFI_DOCS + PRODUCT_DOCS
ESP32_DOCS = WIFI_DOCS + BT_DOCS + WFA_DOCS + MATTER_DOCS + PRODUCT_DOCS
ESP32C2_DOCS = WIFI_DOCS + BLE_DOCS + BT_DOCS + WFA_DOCS + MATTER_DOCS + PRODUCT_DOCS
ESP32C3_DOCS = WIFI_DOCS + BLE_DOCS + BT_DOCS + WFA_DOCS + MATTER_DOCS + PRODUCT_DOCS
ESP32C6_DOCS = WIFI_DOCS + BLE_DOCS + BT_DOCS + ZIGBEE_DOCS + WFA_DOCS + MATTER_DOCS + PRODUCT_DOCS
ESP32S2_DOCS = WIFI_DOCS + PRODUCT_DOCS
ESP32S3_DOCS = WIFI_DOCS + BLE_DOCS + BT_DOCS + WFA_DOCS + MATTER_DOCS + PRODUCT_DOCS
ESP32H2_DOCS = BLE_DOCS + BT_DOCS + ZIGBEE_DOCS + MATTER_DOCS

conditional_include_dict = {'esp8266':ESP8266_DOCS,
                            'esp32':ESP32_DOCS,
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

html_js_files = ['js/chatbot_widget.js']
html_css_files = ['js/chatbot_widget.css']

# Extra options required by sphinx_idf_theme
project_slug = 'esp-test-tools'

# Contains info used for constructing target and version selector
# Can also be hosted externally, see esp-idf for example
versions_url = './_static/js/docs_version.js'

# Final PDF filename will contains target and version
pdf_file_prefix = u'esp-test-tools'

# Add Tracking id for Google Analytics
google_analytics_id = ''

project_homepage = 'https://github.com/espressif/esp-test-tools'

# --- Customized LaTeX configurations ----------------

# Customized titlepage
titlepage = ''
with open('../_static/titlepage.tex') as f:
    titlepage = f.read()

preamble_extra = r'''
% ToC
\makeatletter
\renewcommand{\l@section}[2]{\vspace{14pt}\@dottedtocline{2}{0pt}{30pt}{\LARGE\bfseries\textcolor{LochmaraColor}{#1}}{#2}}
\renewcommand{\l@subsection}[2]{\@dottedtocline{2}{0pt}{30pt}{\textcolor{LochmaraColor}{#1}}{#2}}
\renewcommand{\@dotsep}{10000}
\makeatother

% Line spacing
\linespread{1.3}

% Make text left-aligned
\raggedright
'''

# LaTeX Figure alignment
latex_elements['figure_align'] = 'H'

# Remove empty pages after ToC and end of chapter
latex_elements['extraclassoptions'] = 'openany,oneside'

# Use customized titlepage with version number
latex_elements['maketitle'] = titlepage

# Set document class
latex_docclass = {
    'howto': 'article',
    'manual': 'article',
}

# Start a document from Section instead of Chapter
latex_toplevel_sectioning = 'section'

# Set the path of the logo \sphinxlogo used in the titlepage
latex_logo = '../_static/esp-logo-standard-vertical.pdf'