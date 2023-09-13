from esp_docs.conf_docs import *  # noqa: F403,F401

languages = ['en', 'zh_CN']
idf_targets = ['esp8266', 'esp32', 'esp32s2', 'esp32s3', 'esp32c3', 'esp32h2', 'esp32c2', 'esp32c6', 'esp32p4']

extensions += ['sphinx_copybutton',
               'sphinxcontrib.wavedrom',
               'linuxdoc.rstFlatTable',
               ]

# link roles config
github_repo = 'espressif/esp-test-tool'

# context used by sphinx_idf_theme
html_context['github_user'] = 'espressif'
html_context['github_repo'] = 'esp-test-tool'

html_static_path = ['../_static']

# Extra options required by sphinx_idf_theme
project_slug = 'esp-test-tool'

# Contains info used for constructing target and version selector
# Can also be hosted externally, see esp-idf for example
versions_url = './_static/docs_version.js'

# Final PDF filename will contains target and version
pdf_file_prefix = u'esp-test-tool'

# Add Tracking id for Google Analytics
google_analytics_id = 'UA-132861133-1'

project_homepage = 'https://github.com/espressif/esp-test-tool'
