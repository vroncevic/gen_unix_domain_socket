# -*- coding: utf-8 -*-

import os
import sys
sys.path.insert(0, os.path.abspath('../../'))
project = u'gen_unix_domain_socket'
copyright = u'2018, Vladimir Roncevic <elektron.ronca@gmail.com>'
author = u'Vladimir Roncevic <elektron.ronca@gmail.com>'
version = u'1.0.2'
release = u'https://github.com/vroncevic/gen_unix_domain_socket/releases'
extensions = ['sphinx.ext.autodoc', 'sphinx.ext.viewcode']
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
language = None
exclude_patterns = []
pygments_style = None
html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
htmlhelp_basename = 'gen_unix_domain_socketdoc'
latex_elements = {}
latex_documents = [(
    master_doc, 'gen_unix_domain_socket.tex',
    u'gen\\_unix\\_domain\\_socket Documentation',
    u'Vladimir Roncevic \\textless{}elektron.ronca@gmail.com\\textgreater{}',
    'manual'
)]
man_pages = [(
    master_doc, 'gen_unix_domain_socket',
    u'gen_unix_domain_socket Documentation', [author], 1
)]
texinfo_documents = [(
    master_doc, 'gen_unix_domain_socket',
    u'gen_unix_domain_socket Documentation', author, 'gen_unix_domain_socket',
    'One line description of project.', 'Miscellaneous'
)]
epub_title = project
epub_exclude_files = ['search.html']
