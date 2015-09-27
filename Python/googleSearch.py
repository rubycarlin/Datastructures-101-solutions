from twill.commands import *
import twill.browser 
browser = get_browser()

browser.go('https://en.wikipedia.org/')
form = browser.get_form("1");
print form
print type(form)
field = browser.get_form_field(form, "search");
field._value__set("twill")
print field
print type(field)
##x = fv("1", "search", "twill")
##print x
formaction('1', 'https://en.wikipedia.org/')
##print x
showforms()
x = browser.submit('go')
browser.reload()
x = browser.get_url()
print x
##showforms()
##showlinks()
