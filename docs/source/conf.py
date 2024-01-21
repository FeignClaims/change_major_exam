# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = '计软智网转专业试题回忆版、模拟题及参考解答'
copyright = '2024, FeignClaims'
author = 'FeignClaims'
release = 'v1.0.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ['sphinx_togglebutton', 'sphinx.ext.todo', 'sphinx.ext.graphviz', 'sphinx.ext.extlinks']

extlinks = {'godbolt': ('https://godbolt.org/z/%s', '[在线代码 %s]')}

togglebutton_hint = ""
togglebutton_hint_hide = ""

templates_path = ['_templates']
exclude_patterns = []

rst_prolog = open('_static/inline_cpp.rst', 'r').read() + open('_static/links.rst', 'r').read()

language = 'zh_CN'

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
