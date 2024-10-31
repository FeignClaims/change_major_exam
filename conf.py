# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = '计软智网转专业试题回忆版、模拟题及参考解答'
copyright = '2024, FeignClaims'
author = 'FeignClaims'
html_title = f'{project}'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'myst_parser',
    'sphinx.ext.extlinks',
    'sphinx.ext.graphviz',
    'sphinx.ext.intersphinx',
    'sphinx.ext.todo',
    'sphinx_copybutton',
    'sphinx_design',
    'sphinx_examples',
    'sphinx_last_updated_by_git',
    'sphinx_sitemap',
    'sphinx_tabs.tabs',
    'sphinx_togglebutton',
    'sphinxext.opengraph',
]

intersphinx_mapping = {
    "question_board": ("https://question-board.readthedocs.io/", "https://question-board.readthedocs.io/objects.inv"),
}
intersphinx_disabled_reftypes = ["*"]

extlinks = {'godbolt': ('https://godbolt.org/z/%s', '[在线代码 %s]')}

togglebutton_hint = "点击展开"
togglebutton_hint_hide = "点击隐藏"

templates_path = ['_templates']
exclude_patterns = ['README.md']

rst_prolog = '\n'.join(
    list(
        map(
            lambda filename: open(f'_static/{filename}', 'r', encoding="utf8").read(),
            ['inline_cpp.rst', 'links.rst']))) + '\n'

language = 'zh_CN'

html_copy_source = False
html_show_sourcelink = False

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_book_theme'
html_theme_options = {
    "icon_links": [
        {
            "name": "GitHub",
            "url": "https://github.com/FeignClaims/change_major_exam",
            "icon": "fa-brands fa-github",
        }
    ],
    'repository_url': 'https://github.com/FeignClaims/change_major_exam',
    'show_nav_level': 0,
    'show_prev_next': True,
    'show_toc_level': 2,
    'use_edit_page_button': True,
    'use_issues_button': True,
    'use_sidenotes': True,
    'use_source_button': True,
}
html_static_path = ['_static', '_theme']
html_favicon = '_static/favicon.png'
html_search_language = 'zh'
html_last_updated_fmt = '%Y-%m-%d %H:%M:%S'
git_last_updated_timezone = 'Asia/Shanghai'
html_baseurl = 'https://change-major-exam.readthedocs.io/'
sitemap_filename = 'sitemapindex.xml'
sitemap_url_scheme = '{link}'
html_extra_path = [
    '_static/robots.txt',
    '_verification/5e34747cf23e02efb98960efb9a89f27.txt',
    '_verification/baidu_verify_codeva-dckf2PIPnk.html',
    '_verification/c161d633fe0148f6a08c5afb5e230d50.txt',
    '_verification/google13ac7719c05e0aea.html',
    '_verification/sogousiteverification.txt',
]


def setup(app):
    app.add_css_file("theme.css")
